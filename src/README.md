		├── c_api
		│   ├── c_api.cc
		│   ├── c_api_error.cc
		│   └── c_api_error.h
		├── cli_main.cc  主程序-包含参数配置及任务调度
		├── common
		│   ├── base64.h
		│   ├── bitmap.h
		│   ├── common.cc
		│   ├── common.h
		│   ├── config.h
		│   ├── group_data.h
		│   ├── io.h
		│   ├── math.h
		│   ├── quantile.h
		│   ├── random.h
		│   ├── sync.h
		│   └── thread_local.h
		├── data
		│   ├── data.cc
		│   ├── simple_csr_source.cc
		│   ├── simple_csr_source.h
		│   ├── simple_dmatrix.cc
		│   ├── simple_dmatrix.h
		│   ├── sparse_batch_page.h
		│   ├── sparse_page_dmatrix.cc
		│   ├── sparse_page_dmatrix.h
		│   ├── sparse_page_raw_format.cc
		│   ├── sparse_page_source.cc
		│   ├── sparse_page_source.h
		│   └── sparse_page_writer.cc
		├── gbm
		│   ├── gblinear.cc
		│   ├── gbm.cc GB的注册-目前包含两种: gblinear gbtree
		│   └── gbtree.cc
		├── learner.cc
		├── log
		├── logging.cc
		├── metric  结果度量方法
		│   ├── elementwise_metric.cc  用于基于instance计算loss的场景-包括：rmse  mae  logloss  error  poisson-nloglik
		│   ├── metric.cc  定义了metric的接口类Metric
		│   ├── multiclass_metric.cc  用于多类分类器-包括merror mlogloss
		│   └── rank_metric.cc  用于learning to rank-包括 AMS auc  pre  ndcg  map
		├── objective  loss计算方式
		│   ├── multiclass_obj.cc  多分类的loss(softmax)及grad计算
		│   ├── objective.cc  定义了objective的接口类ObjFunction
		│   ├── rank_obj.cc  用于rank的多种loss及grad计算
		│   └── regression_obj.cc  线性回归 逻辑回归 泊松回归等loss及grad
		└── tree
		    ├── param.h
		    ├── tree_model.cc
		    ├── tree_updater.cc
		    ├── updater_basemaker-inl.h
		    ├── updater_colmaker.cc
		    ├── updater_histmaker.cc
		    ├── updater_prune.cc
		    ├── updater_refresh.cc
		    ├── updater_skmaker.cc
		    └── updater_sync.cc
