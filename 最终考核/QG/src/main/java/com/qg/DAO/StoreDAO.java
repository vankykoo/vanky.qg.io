package com.qg.DAO;

import com.qg.pojo.Goods;
import com.qg.pojo.Store;
import com.qg.util.JDBCUtils;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class StoreDAO extends BasicDAO<Store>{
    //查找所有商品数据
    public List<Store> selectManyStore(String sql,Object... params){
        Store store = null;
        String sqlToStore = "select * from tb_store where store_id =?";
        List<Store> storeList = new ArrayList<>();
        ResultSet resultSet = select(sql, Store.class, params);
        try {
            while (resultSet.next()){
                Integer storeId = resultSet.getInt(1);
                store = selectOneStore(sqlToStore, storeId);
                storeList.add(store);
            }
            return storeList;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    //查找一条数据
    public Store selectOneStore(String sql,Object... params){
        Store store = null;
        ResultSet resultSet = select(sql, Store.class, params);
        try {
            if (resultSet.next()){
                Integer storeId = resultSet.getInt(1);
                String storeName = resultSet.getNString(2);
                String storeLogo = resultSet.getNString(3);
                String storeAddress = resultSet.getNString(4);
                //店主Id
                Integer shopkeeperId = resultSet.getInt(5);
                store = new Store();
                store.setStoreId(storeId);
                store.setStoreName(storeName);
                store.setStoreLogo(storeLogo);
                store.setStoreAddress(storeAddress);
                store.setShopkeeperId(shopkeeperId);
            }
            return store;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    //显示所有店铺
    public List<Store> selectAllStores(){
        String sql = "select * from tb_store";
        return selectManyStore(sql);
    }

    public List<Store> selectStoreByName(String storeName){
        String sql = "select * from tb_store where store_name like ?";
        return selectManyStore(sql,storeName);
    }

    public Store selectStoreByUserId(Integer userId){
        String sql = "select * from tb_store where store_user_id =?";
        return selectOneStore(sql,userId);
    }

    public void updateStore(Store store){
        String sql = "update tb_store set store_name =?, store_picture =?, store_address =? where store_id =?";
        update(sql,store.getStoreName(),store.getStoreLogo(),store.getStoreAddress(),store.getStoreId());
    }

    public void OpenStore(Store store){
        String sql = "insert into tb_store (store_name,store_picture," +
                "store_address,store_user_id) values (?,?,?,?)";
        update(sql,store.getStoreName(),store.getStoreLogo(),
                store.getStoreAddress(), store.getShopkeeperId());
        String sqlForIdentity = "update tb_user set identity = 2 where user_id =?";
        update(sqlForIdentity,store.getShopkeeperId());
    }

    //获取最后插入的记录的storeId
    public Integer getStoreId(){
        String sql = "select * from tb_store order by store_id desc limit 1";
        Store store = selectOneStore(sql);
        return store.getStoreId();
    }
}
