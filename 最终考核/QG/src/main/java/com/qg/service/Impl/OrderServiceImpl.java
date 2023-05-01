package com.qg.service.Impl;

import com.qg.DAO.GoodsDAO;
import com.qg.DAO.OrderDAO;
import com.qg.DAO.StoreDAO;
import com.qg.pojo.Goods;
import com.qg.pojo.Order;
import com.qg.pojo.Store;
import com.qg.service.OrderService;

import java.util.List;

public class OrderServiceImpl implements OrderService {
    OrderDAO orderDAO = new OrderDAO();


    @Override
    public List<Order> selectAllOrders(Integer userId) {
        return orderDAO.selectAllOrder(userId);
    }

    @Override
    public void addToOrderByIds(Integer[] goodsIds,Integer userId){
        orderDAO.addToOrderByIds(goodsIds,userId);
    }

    @Override
    public List<Order> selectByStoreId(Integer storeId) {
        return orderDAO.selectByStoreId(storeId);
    }

    @Override
    public void sendOutGoods(Integer orderId) {
        String sql = "update tb_order set order_state = 2 where order_id =?";
        orderDAO.update(sql,orderId);
    }

    @Override
    public void afterService(Integer orderId) {
        String sql = "update tb_order set order_state = 5 where order_id =?";
        orderDAO.update(sql,orderId);
    }

    @Override
    public void confirmReceipt(Integer orderId) {
        String sql = "update tb_order set order_state = 4 where order_id =?";
        orderDAO.update(sql,orderId);
    }

    @Override
    public void applyServiceAfterSales(Integer orderId) {
        String sql = "update tb_order set order_state = 3 where order_id =?";
        orderDAO.update(sql,orderId);
    }

    @Override
    public void orderCompleted(Integer orderId) {
        String sql = "update tb_order set order_state = 5 where order_id =?";
        orderDAO.update(sql,orderId);
    }

}
