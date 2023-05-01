package com.qg.service;

import com.qg.pojo.Goods;
import com.qg.pojo.Store;

import java.util.List;

public interface StoreService {
    /**
     * 查看所有店铺
     * @return
     */
    List<Store> selectAllStores();

    /**
     * 搜索店铺
     * @param storeName
     * @return
     */
    List<Store> selectStoreByName(String storeName);

    /**
     * 查看用户的店铺
     * @param userId
     * @return
     */
    Store selectStoreByUserId(Integer userId);

    /**
     * 修改店铺信息
     * @param store
     */
    void updateStore(Store store);

    /**
     * 开店铺
     * @param store
     */
    void openStore(Store store);

    /**
     * 用id查找店铺
     * @param storeId
     * @return
     */
    Store selectStoreById(Integer storeId);
}
