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

package com.facebook.thrift;

public class TransportAdapter {
  public static com.facebook.thrift.transport.TTransport adaptTransport(
      org.apache.thrift.transport.TTransport apacheTransport) {
    return new ApacheToFacebookTransportAdapter(apacheTransport);
  }

  public static org.apache.thrift.transport.TTransport adaptTransport(
      com.facebook.thrift.transport.TTransport facebookTransport) {
    return new FacebookToApacheTransportAdapter(facebookTransport);
  }
}
