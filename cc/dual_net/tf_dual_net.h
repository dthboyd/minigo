// Copyright 2018 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef CC_DUAL_NET_TF_DUAL_NET_H_
#define CC_DUAL_NET_TF_DUAL_NET_H_

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "absl/types/span.h"
#include "cc/constants.h"
#include "cc/dual_net/dual_net.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/public/session.h"

namespace minigo {

// TODO(csigg): Move to implementation file.
class TfDualNet : public DualNet {
 public:
  explicit TfDualNet(std::string graph_path);
  ~TfDualNet() override;

  void RunMany(std::vector<const BoardFeatures*> features,
               std::vector<Output*> outputs, std::string* model) override;

 private:
  std::unique_ptr<tensorflow::Session> session_;
  std::vector<std::pair<std::string, tensorflow::Tensor>> inputs_;
  std::vector<std::string> output_names_;
  std::vector<tensorflow::Tensor> outputs_;
  std::string graph_path_;
};

std::unique_ptr<DualNet> NewTfDualNet(const std::string& graph_path);

}  // namespace minigo

#endif  // CC_DUAL_NET_TF_DUAL_NET_H_
