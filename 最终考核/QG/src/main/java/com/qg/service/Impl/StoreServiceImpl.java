package com.qg.service.Impl;

import com.qg.DAO.GoodsDAO;
import com.qg.DAO.StoreDAO;
import com.qg.pojo.Goods;
import com.qg.pojo.Store;
import com.qg.service.StoreService;

import java.util.List;

public class StoreServiceImpl implements StoreService {
    private StoreDAO storeDAO = new StoreDAO();

    @Override
    public List<Store> selectAllStores() {
        return storeDAO.selectAllStores();
    }

    @Override
    public List<Store> selectStoreByName(String storeName) {
        return storeDAO.selectStoreByName(storeName);
    }

    @Override
    public Store selectStoreByUserId(Integer userId) {
        return storeDAO.selectStoreByUserId(userId);
    }

    @Override
    public void updateStore(Store store) {
        storeDAO.updateStore(store);
    }

    @Override
    public void openStore(Store store) {
        storeDAO.OpenStore(store);
    }

    @Override
    public Store selectStoreById(Integer storeId) {
        String sql = "select * from tb_store where store_id =?";
        Store store = storeDAO.selectOneStore(sql, storeId);
        return store;
    }
}
