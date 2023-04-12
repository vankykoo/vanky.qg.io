package com.qg.service;

import com.qg.mapper.UserMapper;
import com.qg.pojo.User;
import com.qg.util.SqlSessionFactoryUtils;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;

public class UserServiceImpl implements UserService {
    //1.获取SqlSessionFactory 工厂对象
    SqlSessionFactory factory = SqlSessionFactoryUtils.getSqlSessionFactory();

    @Override
    public User select(String userName) {
        //2.获取sqlSession
        SqlSession sqlSession = factory.openSession();
        //3.获取BrandMapper
        UserMapper mapper = sqlSession.getMapper(UserMapper.class);
        //4.调用方法
        User user = mapper.select(userName);
        //5.释放资源
        sqlSession.close();

        return user;
    }

    @Override
    public void add(User user) {
        //2.获取sqlSession
        SqlSession sqlSession = factory.openSession();
        //3.获取BrandMapper
        UserMapper mapper = sqlSession.getMapper(UserMapper.class);
        //4.调用方法
        mapper.add(user);
        sqlSession.commit();

        //5.释放资源
        sqlSession.close();
    }

}
