/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "thrift/compiler/test/fixtures/exceptions/gen-cpp2/module_types.h"
#include "thrift/compiler/test/fixtures/exceptions/gen-cpp2/module_types.tcc"

#include <thrift/lib/cpp2/gen/module_types_cpp.h>

#include "thrift/compiler/test/fixtures/exceptions/gen-cpp2/module_data.h"


namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::Banal>::translateFieldName(
    FOLLY_MAYBE_UNUSED folly::StringPiece _fname,
    FOLLY_MAYBE_UNUSED int16_t& fid,
    FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
  if (false) {}
}
void TccStructTraits<::cpp2::Fiery>::translateFieldName(
    FOLLY_MAYBE_UNUSED folly::StringPiece _fname,
    FOLLY_MAYBE_UNUSED int16_t& fid,
    FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
  if (false) {}
  else if (_fname == "message") {
    fid = 1;
    _ftype = apache::thrift::protocol::T_STRING;
  }
}
void TccStructTraits<::cpp2::Serious>::translateFieldName(
    FOLLY_MAYBE_UNUSED folly::StringPiece _fname,
    FOLLY_MAYBE_UNUSED int16_t& fid,
    FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
  if (false) {}
  else if (_fname == "sonnet") {
    fid = 1;
    _ftype = apache::thrift::protocol::T_STRING;
  }
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace cpp2 {

Banal::Banal(apache::thrift::FragileConstructor) {}

void Banal::__clear() {
  // clear all fields
}

bool Banal::operator==(const Banal& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  return true;
}

bool Banal::operator<(const Banal& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  return false;
}


void swap(Banal& a, Banal& b) {
  using ::std::swap;
  (void)a;
  (void)b;
}

template void Banal::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t Banal::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t Banal::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t Banal::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void Banal::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t Banal::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t Banal::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t Banal::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

} // cpp2
namespace cpp2 {

Fiery::Fiery(apache::thrift::FragileConstructor, ::std::string message__arg) :
    message(std::move(message__arg)) {}

void Fiery::__clear() {
  // clear all fields
  message = apache::thrift::StringTraits< std::string>::fromStringLiteral("");
}

bool Fiery::operator==(const Fiery& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.message == rhs.message)) {
    return false;
  }
  return true;
}

bool Fiery::operator<(const Fiery& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.message == rhs.message)) {
    return lhs.message < rhs.message;
  }
  return false;
}


void swap(Fiery& a, Fiery& b) {
  using ::std::swap;
  swap(a.message, b.message);
}

template void Fiery::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t Fiery::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t Fiery::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t Fiery::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void Fiery::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t Fiery::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t Fiery::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t Fiery::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

} // cpp2
namespace cpp2 {

Serious::Serious(apache::thrift::FragileConstructor, ::std::string sonnet__arg) :
    sonnet(std::move(sonnet__arg)) {
  __isset.sonnet = true;
}

void Serious::__clear() {
  // clear all fields
  sonnet = apache::thrift::StringTraits< std::string>::fromStringLiteral("");
  __isset = {};
}

bool Serious::operator==(const Serious& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (lhs.__isset.sonnet != rhs.__isset.sonnet) {
    return false;
  }
  if (lhs.__isset.sonnet) {
    if (!(lhs.sonnet == rhs.sonnet)) {
      return false;
    }
  }
  return true;
}

bool Serious::operator<(const Serious& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (lhs.__isset.sonnet != rhs.__isset.sonnet) {
    return lhs.__isset.sonnet < rhs.__isset.sonnet;
  }
  if (lhs.__isset.sonnet) {
    if (!(lhs.sonnet == rhs.sonnet)) {
      return lhs.sonnet < rhs.sonnet;
    }
  }
  return false;
}


void swap(Serious& a, Serious& b) {
  using ::std::swap;
  swap(a.sonnet_ref().value_unchecked(), b.sonnet_ref().value_unchecked());
  swap(a.__isset, b.__isset);
}

template void Serious::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t Serious::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t Serious::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t Serious::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void Serious::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t Serious::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t Serious::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t Serious::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

} // cpp2
