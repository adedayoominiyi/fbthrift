/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <thrift/lib/cpp/Reflection.h>
#include <thrift/lib/cpp2/reflection/legacy_reflection.h>
#include <thrift/test/gen-cpp2/ReflectionTest_fatal_types.h>

#include <folly/portability/GTest.h>

using namespace apache::thrift;
using namespace apache::thrift::reflection;
using namespace apache::thrift::test;

template <typename T>
using refl = legacy_reflection<T>;

TEST(Reflection, Basic) {
  auto schema = refl<ReflectionTestStruct1>::schema();
  EXPECT_EQ(Type::TYPE_STRUCT, getType(refl<ReflectionTestStruct1>::id()));

  auto& s1 = schema.dataTypes.at(refl<ReflectionTestStruct1>::id());
  EXPECT_EQ("struct ReflectionTest.ReflectionTestStruct1", s1.name);
  EXPECT_EQ(refl<ReflectionTestStruct1>::id(), schema.names.at(s1.name));
  EXPECT_EQ(4, s1.fields_ref()->size());

  {
    auto& f = s1.fields_ref()->at(1);
    EXPECT_TRUE(f.isRequired);
    EXPECT_EQ(int(Type::TYPE_I32), f.type);
    EXPECT_EQ("a", f.name);
    EXPECT_EQ(1, f.order);
    EXPECT_FALSE(f.__isset.annotations);
  }

  {
    auto& f = s1.fields_ref()->at(2);
    EXPECT_FALSE(f.isRequired);
    EXPECT_EQ(int(Type::TYPE_I32), f.type);
    EXPECT_EQ("b", f.name);
    EXPECT_EQ(2, f.order);
    EXPECT_FALSE(f.__isset.annotations);
  }

  {
    auto& f = s1.fields_ref()->at(3);
    // Fields that aren't declared "required" or "optional" are always
    // sent on the wire, so we'll consider them "required" for our purposes.
    EXPECT_TRUE(f.isRequired);
    EXPECT_EQ(int(Type::TYPE_I32), f.type);
    EXPECT_EQ("c", f.name);
    EXPECT_EQ(0, f.order);
    EXPECT_FALSE(f.__isset.annotations);
  }

  {
    auto& f = s1.fields_ref()->at(4);
    EXPECT_TRUE(f.isRequired);
    EXPECT_EQ(int(Type::TYPE_STRING), f.type);
    EXPECT_EQ("d", f.name);
    EXPECT_EQ(3, f.order);
    EXPECT_TRUE(f.__isset.annotations);
    EXPECT_EQ("hello", f.annotations_ref()->at("some.field.annotation"));
    EXPECT_EQ("1", f.annotations_ref()->at("some.other.annotation"));
    EXPECT_EQ("1", f.annotations_ref()->at("annotation.without.value"));
  }
}

TEST(Reflection, Complex) {
  auto schema = refl<ReflectionTestStruct2>::schema();
  EXPECT_EQ(Type::TYPE_STRUCT, getType(refl<ReflectionTestStruct2>::id()));

  auto& s2 = schema.dataTypes.at(refl<ReflectionTestStruct2>::id());
  EXPECT_EQ("struct ReflectionTest.ReflectionTestStruct2", s2.name);
  EXPECT_EQ(refl<ReflectionTestStruct2>::id(), schema.names.at(s2.name));
  EXPECT_TRUE(s2.__isset.fields);
  EXPECT_EQ(4, s2.fields_ref()->size());

  {
    auto& f = s2.fields_ref()->at(1);
    EXPECT_TRUE(f.isRequired);
    EXPECT_EQ(0, f.order);
    EXPECT_EQ(Type::TYPE_MAP, getType(f.type));

    auto& m = schema.dataTypes.at(f.type);
    EXPECT_EQ("map<byte, struct ReflectionTest.ReflectionTestStruct1>", m.name);
    EXPECT_EQ(f.type, schema.names.at(m.name));
    EXPECT_EQ(int(Type::TYPE_BYTE), *m.mapKeyType_ref());
    EXPECT_EQ(refl<ReflectionTestStruct1>::id(), *m.valueType_ref());
  }

  {
    auto& f = s2.fields_ref()->at(2);
    EXPECT_TRUE(f.isRequired);
    EXPECT_EQ(1, f.order);
    EXPECT_EQ(Type::TYPE_SET, getType(f.type));

    auto& m = schema.dataTypes.at(f.type);
    EXPECT_EQ("set<string>", m.name);
    EXPECT_EQ(f.type, schema.names.at("set<string>"));
    EXPECT_EQ(int(Type::TYPE_STRING), *m.valueType_ref());
  }

  {
    auto& f = s2.fields_ref()->at(3);
    EXPECT_TRUE(f.isRequired);
    EXPECT_EQ(2, f.order);
    EXPECT_EQ(Type::TYPE_LIST, getType(f.type));

    auto& m = schema.dataTypes.at(f.type);
    EXPECT_EQ("list<i64>", m.name);
    EXPECT_EQ(f.type, schema.names.at(m.name));
    EXPECT_EQ(int(Type::TYPE_I64), *m.valueType_ref());
  }

  {
    auto& f = s2.fields_ref()->at(4);
    EXPECT_TRUE(f.isRequired);
    EXPECT_EQ(Type::TYPE_ENUM, getType(f.type));

    auto& m = schema.dataTypes.at(f.type);
    EXPECT_EQ("enum ReflectionTest.ReflectionTestEnum", m.name);
    EXPECT_EQ(f.type, schema.names.at(m.name));
    EXPECT_TRUE(m.__isset.enumValues);
    EXPECT_EQ(2, m.enumValues_ref()->size());
    EXPECT_EQ(5, m.enumValues_ref()->at("FOO"));
    EXPECT_EQ(4, m.enumValues_ref()->at("BAR"));
  }
}
