package com.qg.DAO;

import com.qg.pojo.Goods;
import com.qg.pojo.Order;
import com.qg.pojo.Store;
import com.qg.pojo.User;
import com.qg.util.JDBCUtils;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;

public class OrderDAO extends BasicDAO<Order> {
    JDBCUtils jdbcUtils = new JDBCUtils();
    //查找所有订单数据
    public List<Order> selectManyOrder(String sql,Object... params){
        BasicDAO<Order> basicDAO =new BasicDAO<>();
        Order order = null;
        String sqlToOne = "select * from tb_order where order_id =?";
        List<Order> orderList = new ArrayList<>();
        ResultSet resultSet = basicDAO.select(sql, Order.class,params);
        try {
            while (resultSet.next()){
                Integer orderId = resultSet.getInt(1);
                order = selectOneOrder(sqlToOne,orderId);
                orderList.add(order);
            }
            return orderList;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }finally {
            jdbcUtils.close(null,null,null);
        }

    }

    public Order selectOneOrder(String sql,Object... params){
        BasicDAO<Order> basicDAO =new BasicDAO<>();
        GoodsDAO goodsDAO = new GoodsDAO();
        UserDAO userDAO = new UserDAO();
        Order order = null;
        User user = null;
        Goods goods = null;
        ResultSet resultSet = basicDAO.select(sql, Order.class, params);
        String sqlForUser = "select * from tb_user where user_id =?";
        String sqlForGoods = "select * from tb_goods where goods_id =?";
        try {
            if (resultSet.next()){
                Integer orderId = resultSet.getInt(1);
                Integer orderState = resultSet.getInt(2);
                String storePlace = resultSet.getString(4);

                Integer userId = resultSet.getInt(5);
                user = userDAO.selectUser(sqlForUser,userId);
                String customerPlace = user.getUserAddress();
                String userName = user.getUserName();
                String phoneNumber = user.getPhoneNumber();

                String orderTime = resultSet.getString(6);
                String orderTimeString = orderTime.toString();
                Integer goodsId = resultSet.getInt(7);

                goods = goodsDAO.selectOneGoods(sqlForGoods, goodsId);
                String goodsPicture = goods.getGoodsPicture();
                String goodsName = goods.getGoodsName();

                Integer storeId = resultSet.getInt(10);

                order = new Order(orderId,orderState,customerPlace,goodsName,storePlace,userId,orderTimeString,goodsId,goodsPicture,storeId,userName,phoneNumber);
            }
            return order;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }finally {
            jdbcUtils.close(null,null,null);
        }
    }

    //购买后加入订单
    public void addToOrderByIds(Integer[] goodsIds,Integer userId){
        GoodsDAO goodsDAO = new GoodsDAO();
        StoreDAO storeDAO = new StoreDAO();
        UserDAO userDAO = new UserDAO();
        Goods goods = null;
        Store store = null;
        User user = null;
        String sqlForGoods = "select * from tb_goods where goods_id =?";
        String sqlForStore = "select * from tb_store where store_id =?";
        String sqlForUser = "select * from tb_user where user_id =?";
        String sqlToInsert = "insert into tb_order (order_id,order_state,customer_place,store_place,user_id,order_time,goods_id,goods_picture,goods_name,goods_store_id)" +
                "values (null,?,?,?,?,?,?,?,?,?)";
        for (int i = 0; i < goodsIds.length; i++) {
            goods = goodsDAO.selectOneGoods(sqlForGoods,goodsIds[i]);
            store = storeDAO.selectOneStore(sqlForStore, goods.getStoreId());
            user = userDAO.selectUser(sqlForUser, userId);

            LocalDateTime now = LocalDateTime.now();
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
            String formattedDateTime = now.format(formatter);

            String userAddress = user.getUserAddress();
            String storeAddress = store.getStoreAddress();
            Integer goodsId = goods.getGoodsId();
            String goodsPicture = goods.getGoodsPicture();
            String goodsName = goods.getGoodsName();
            Integer storeId = goods.getStoreId();

            update(sqlToInsert,1,userAddress,storeAddress,userId,formattedDateTime,goodsId,goodsPicture,goodsName,storeId);

        }
    }

    public List<Order> selectAllOrder(Integer userId){
        String sql = "select * from tb_order where user_id = ?";
        return selectManyOrder(sql,userId);
    }

    public List<Order> selectByStoreId(Integer storeId){
        String sql = "select * from tb_order where goods_store_id =?";
        return selectManyOrder(sql,storeId);
    }

}
