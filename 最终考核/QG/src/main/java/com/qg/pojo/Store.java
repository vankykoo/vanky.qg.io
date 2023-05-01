package com.qg.pojo;

public class Store {
    //店铺id
    private Integer storeId;
    //店铺名
    private String storeName;
    //店铺logo
    private String storeLogo;
    //店铺地址（发货地址）
    private String storeAddress;
    //店主
    private Integer shopkeeperId;

    public Store() {
    }

    public Store(Integer storeId, String storeName, String storeLogo, String storeAddress, Integer shopkeeperId) {
        this.storeId = storeId;
        this.storeName = storeName;
        this.storeLogo = storeLogo;
        this.storeAddress = storeAddress;
        this.shopkeeperId = shopkeeperId;
    }

    public Integer getStoreId() {
        return storeId;
    }

    public void setStoreId(Integer storeId) {
        this.storeId = storeId;
    }

    public String getStoreName() {
        return storeName;
    }

    public void setStoreName(String storeName) {
        this.storeName = storeName;
    }

    public String getStoreLogo() {
        return storeLogo;
    }

    public void setStoreLogo(String storeLogo) {
        this.storeLogo = storeLogo;
    }

    public String getStoreAddress() {
        return storeAddress;
    }

    public void setStoreAddress(String storeAddress) {
        this.storeAddress = storeAddress;
    }

    public Integer getShopkeeperId() {
        return shopkeeperId;
    }

    public void setShopkeeperId(Integer shopkeeperId) {
        this.shopkeeperId = shopkeeperId;
    }

    @Override
    public String toString() {
        return "Store{" +
                "storeId=" + storeId +
                ", storeName='" + storeName + '\'' +
                ", storeLogo='" + storeLogo + '\'' +
                ", storeAddress='" + storeAddress + '\'' +
                ", shopkeeperId=" + shopkeeperId +
                '}';
    }
}
