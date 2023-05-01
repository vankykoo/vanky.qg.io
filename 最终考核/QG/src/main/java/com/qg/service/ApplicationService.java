package com.qg.service;

import com.qg.pojo.Application;

import java.util.List;

public interface ApplicationService {
    /**
     * 查找所有申请
     */
    List<Application> selectAllApplicationByUserId(Integer userId);

    /**
     * 提交申请
     * @param application
     */
    void addToApplication(Application application);

    /**
     * 网站管理员查看所有申请
     * @return
     */
    List<Application> selectAllApplication();

    /**
     * 审核是否同意
     * @param applicationId
     * @param isAgree
     */
    void handleApplication(Integer applicationId,Integer isAgree);
}
