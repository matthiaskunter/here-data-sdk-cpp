/*
 * Copyright (C) 2020 HERE Europe B.V.
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
 *
 * SPDX-License-Identifier: Apache-2.0
 * License-Filename: LICENSE
 */

#pragma once

#include <vector>

#include <rapidjson/document.h>
#include <olp/core/generated/parser/ParserWrapper.h>

namespace mockserver {

struct Status {
  using Ports = std::vector<int32_t>;

  Ports ports;
};

void from_json(const rapidjson::Value& value, Status& x);

inline void from_json(const rapidjson::Value& value, Status& x) {
  x.ports = olp::parser::parse<Status::Ports>(value, "ports");
}

}  // namespace mockserver
