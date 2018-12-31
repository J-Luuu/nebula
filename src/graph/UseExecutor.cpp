/* Copyright (c) 2018 - present, VE Software Inc. All rights reserved
 *
 * This source code is licensed under Apache 2.0 License
 *  (found in the LICENSE.Apache file in the root directory)
 */

#include "base/Base.h"
#include "graph/UseExecutor.h"

namespace nebula {
namespace graph {

UseExecutor::UseExecutor(Sentence *sentence, ExecutionContext *ectx) : Executor(ectx) {
    sentence_ = static_cast<UseSentence*>(sentence);
}


Status UseExecutor::prepare() {
    return Status::OK();
}


void UseExecutor::execute() {
    auto *session = ectx()->rctx()->session();

    // TODO(dutor) Check space's validness and map to type of integer
    session->setSpace(sentence_->space());
    FLOG_INFO("Graph space switched to `%s'", sentence_->space().c_str());

    onFinish_();
}

}   // namespace graph
}   // namespace nebula