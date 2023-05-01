package com.qg.DAO;

import com.qg.pojo.Application;
import com.qg.pojo.Goods;
import com.qg.pojo.User;
import com.qg.util.JDBCUtils;

import java.sql.Date;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class ApplicationDAO extends BasicDAO<Application> {
    JDBCUtils jdbcUtils = new JDBCUtils();

    //封装查找单个
    public Application selectOneApplication(String sql, Object... params) {
        Application application = null;
        ResultSet resultSet = select(sql, Application.class, params);
        try {
            if (resultSet.next()) {
                //从数据库获取
                Integer applicationId = resultSet.getInt(1);
                String applicationPic = resultSet.getString(2);
                String description = resultSet.getString(3);
                Integer applicationState = resultSet.getInt(4);
                Integer applicationUserId = resultSet.getInt(5);
                Integer applicationType = resultSet.getInt(6);
                String applicationUserName = resultSet.getString(7);
                String name = resultSet.getString(8);
                Date applicationDate = resultSet.getDate(9);
                String orderTimeString = applicationDate.toString();
                String address = resultSet.getString(10);
                Integer goodsId = resultSet.getInt(11);
                application = new Application
                        (applicationId,applicationType,applicationUserId,applicationUserName,name,applicationPic,description,orderTimeString,applicationState,address,goodsId);
            }
            return application;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }finally {
            jdbcUtils.close(null,null,null);
        }
    }

    public List<Application> selectManyApplication(String sql,Object... params){
        Application application = null;
        List<Application> applicationList = new ArrayList<>();
        ResultSet resultSet = select(sql, Application.class, params);
        String sqlForApplication = "select * from tb_application where " +
                "application_id =?";
            try {
                while (resultSet.next()){
                    Integer applicationId = resultSet.getInt(1);
                    application = selectOneApplication(sqlForApplication, applicationId);
                    applicationList.add(application);
                }
                return applicationList;
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }finally {
                jdbcUtils.close(null,null,null);
            }
    }

    public List<Application> selectAllApplicationByUserId(Integer userId){
        String sql = "select * from tb_application where user_id =?";
        return selectManyApplication(sql, userId);
    }

    public List<Application> selectAllApplication(){
        String sql = "select * from tb_application";
        return selectManyApplication(sql);
    }

    public void addToApplication(Application application){
        String sql = "insert into tb_application (application_id,application_picture," +
                "application_description,application_state,user_id,application_type," +
                "user_name,application_name,application_date,address,goods_id)\n" +
                "values (null,?,?,?,?,?,?,?,?,?,?)";
        String applicationPic = application.getApplicationPic();
        String description = application.getDescription();
        Integer applicationUserId = application.getApplicationUserId();
        Integer applicationType = application.getApplicationType();
        String applicationUserName = application.getApplicationUserName();
        String name = application.getName();
        String address = application.getAddress();
        Integer goodsId = application.getGoodsId();

        long currentTimeMillis = new java.util.Date().getTime();
        java.sql.Date applicationDate = new java.sql.Date(currentTimeMillis);

        update(sql,applicationPic,description,0,applicationUserId,
                applicationType,applicationUserName,name,applicationDate,address,goodsId);
    }

    public void handleApplication(Integer applicationId,Integer isAgree){
        String sql = "update tb_application set application_state =? where application_id =?";
        update(sql,isAgree,applicationId);
    }
}
