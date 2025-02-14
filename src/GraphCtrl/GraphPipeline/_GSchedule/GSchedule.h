/***************************
@Author: Chunel
@Contact: chunel@foxmail.com
@File: GSchedule.h
@Time: 2023/3/25 19:01
@Desc: 
***************************/

#ifndef CGRAPH_GSCHEDULE_H
#define CGRAPH_GSCHEDULE_H

#include "../../GraphObject.h"
#include "GScheduleDefine.h"

CGRAPH_NAMESPACE_BEGIN

class GSchedule : public GraphObject {
protected:
    /**
     * 将调度资源修改为 shared 模式
     * @param tp
     * @return
     */
    CStatus makeShared(UThreadPoolPtr tp);

    /**
     * 获取线程池信息
     * @return
     */
    UThreadPoolPtr getThreadPool();

    CStatus init() override;

    CStatus run() override;

    CStatus destroy() final;

    ~GSchedule() override;

private:
    UThreadPoolPtr unique_tp_ = nullptr;            // 内部独占的线程池
    UThreadPoolPtr shared_tp_ = nullptr;            // 外部输入的线程池
    UThreadPoolConfig config_;                      // 线程池的配置信息
    GScheduleType type_ = GScheduleType::UNIQUE;    // 调度类型

    friend class GPipeline;
};

CGRAPH_NAMESPACE_END

#endif //CGRAPH_GSCHEDULE_H
