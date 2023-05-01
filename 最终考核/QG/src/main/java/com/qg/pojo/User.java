package com.qg.pojo;
/**
 * 用户信息
 * @author vanky
 */
public class User {
    //用户id
    private Integer userId;
    //用户名
    private String userName;
    //用户密码
    private String password;
    //用户头像
    private String userPicture;
    //住址
    private String userAddress;
    //电话号码
    private String phoneNumber;
    /**
     * 默认为普通用户：1
     * 店铺管理员：2
     * 网站管理员：3
     */
    private Integer userIdentity;
    //用户的店铺
    private Integer storeId;

    public User(Integer userId, String userName, String password, String userPicture, String userAddress, String phoneNumber, Integer userIdentity, Integer storeId) {
        this.userId = userId;
        this.userName = userName;
        this.password = password;
        this.userPicture = userPicture;
        this.userAddress = userAddress;
        this.phoneNumber = phoneNumber;
        this.userIdentity = userIdentity;
        this.storeId = storeId;
    }

    public Integer getUserId() {
        return userId;
    }

    public void setUserId(Integer userId) {
        this.userId = userId;
    }

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getUserPicture() {
        return userPicture;
    }

    public void setUserPicture(String userPicture) {
        this.userPicture = userPicture;
    }

    public String getUserAddress() {
        return userAddress;
    }

    public void setUserAddress(String userAddress) {
        this.userAddress = userAddress;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    public Integer getUserIdentity() {
        return userIdentity;
    }

    public void setUserIdentity(Integer userIdentity) {
        this.userIdentity = userIdentity;
    }

    public Integer getStoreId() {
        return storeId;
    }

    public void setStoreId(Integer storeId) {
        this.storeId = storeId;
    }

    //逻辑视图
    public String getUserIdentityStr(){
        switch (userIdentity){
            case 1:
                return "普通用户";
            case 2:
                return "店铺管理员";
            case 3:
                return "网站管理员";
            default:
                return "未知";
        }
    }

    @Override
    public String toString() {
        return "User{" +
                "userId=" + userId +
                ", userName='" + userName + '\'' +
                ", password='" + password + '\'' +
                ", userPicture='" + userPicture + '\'' +
                ", userAddress='" + userAddress + '\'' +
                ", phoneNumber='" + phoneNumber + '\'' +
                ", userIdentity=" + userIdentity +
                ", storeId=" + storeId +
                '}';
    }
}
