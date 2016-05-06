/*!
 * Copyright 2015 by Contributors
 * \file metric_registry.cc
 * \brief Registry of objective functions.
 */
#include <xgboost/metric.h>
#include <dmlc/registry.h>

namespace dmlc {
DMLC_REGISTRY_ENABLE(::xgboost::MetricReg);
}

// 两种metric的形式，一种是只需提供名称eg: auc rmse
// 另一种需要提供名称及一个参数以name@param形式给出eg: ams@k map@k
// 调用方式可在learner.cc中查看 Metric::Create(ams@k)
namespace xgboost {
Metric* Metric::Create(const std::string& name) {
  std::string buf = name;
  std::string prefix = name;
  auto pos = buf.find('@');
  if (pos == std::string::npos) { // 若找不到@,表示不包含param
    auto *e = ::dmlc::Registry< ::xgboost::MetricReg>::Get()->Find(name);
    if (e == nullptr) {
      LOG(FATAL) << "Unknown metric function " << name;
    }
    return (e->body)(nullptr); // 此时param默认为nullptr
  } else {
    std::string prefix = buf.substr(0, pos);
    auto *e = ::dmlc::Registry< ::xgboost::MetricReg>::Get()->Find(prefix.c_str());
    if (e == nullptr) {
      LOG(FATAL) << "Unknown metric function " << name;
    }
    return (e->body)(buf.substr(pos + 1, buf.length()).c_str()); // e->body的参数为@后面的param
  }
}
}  // namespace xgboost

namespace xgboost {
namespace metric {
// List of files that will be force linked in static links.
DMLC_REGISTRY_LINK_TAG(elementwise_metric);
DMLC_REGISTRY_LINK_TAG(multiclass_metric);
DMLC_REGISTRY_LINK_TAG(rank_metric);
}  // namespace metric
}  // namespace xgboost
