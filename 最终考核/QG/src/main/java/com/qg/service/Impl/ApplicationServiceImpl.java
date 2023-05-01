package com.qg.service.Impl;

import com.qg.DAO.ApplicationDAO;
import com.qg.pojo.Application;
import com.qg.service.ApplicationService;

import java.util.List;

/**
 * @author vanky
 */
public class ApplicationServiceImpl implements ApplicationService {
    ApplicationDAO applicationDAO = new ApplicationDAO();

    @Override
    public List<Application> selectAllApplicationByUserId(Integer userId) {
        return applicationDAO.selectAllApplicationByUserId(userId);
    }

    @Override
    public void addToApplication(Application application) {
        applicationDAO.addToApplication(application);
    }

    @Override
    public List<Application> selectAllApplication() {
        return applicationDAO.selectAllApplication();
    }

    @Override
    public void handleApplication(Integer applicationId,Integer isAgree) {
        applicationDAO.handleApplication(applicationId,isAgree);
    }

}
