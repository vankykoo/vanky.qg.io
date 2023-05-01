package com.qg.pojo;

public class Application {
    //申请ID
    private Integer applicationId;
    //申请类型：申请开店：1/申请添加商品：2
    private Integer applicationType;
    //申请人id
    private Integer applicationUserId;
    //申请人名字
    private String applicationUserName;
    //申请内容名称
    private String name;
    //申请图片
    private String applicationPic;
    //申请内容
    private String description;
    //申请日期
    private String applicationDate;
    //状态：0表示未处理，1表示同意，2不同意
    private Integer applicationState;
    //地址
    private String address;
    //商品id
    private Integer goodsId;

    public Application() {
    }

    public Application(Integer applicationId, Integer applicationType, Integer applicationUserId, String applicationUserName, String name, String applicationPic, String description, String applicationDate, Integer applicationState, String address, Integer goodsId) {
        this.applicationId = applicationId;
        this.applicationType = applicationType;
        this.applicationUserId = applicationUserId;
        this.applicationUserName = applicationUserName;
        this.name = name;
        this.applicationPic = applicationPic;
        this.description = description;
        this.applicationDate = applicationDate;
        this.applicationState = applicationState;
        this.address = address;
        this.goodsId = goodsId;
    }

    public Integer getApplicationId() {
        return applicationId;
    }

    public void setApplicationId(Integer applicationId) {
        this.applicationId = applicationId;
    }

    public Integer getApplicationType() {
        return applicationType;
    }

    public void setApplicationType(Integer applicationType) {
        this.applicationType = applicationType;
    }

    public Integer getApplicationUserId() {
        return applicationUserId;
    }

    public void setApplicationUserId(Integer applicationUserId) {
        this.applicationUserId = applicationUserId;
    }

    public String getApplicationUserName() {
        return applicationUserName;
    }

    public void setApplicationUserName(String applicationUserName) {
        this.applicationUserName = applicationUserName;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getApplicationPic() {
        return applicationPic;
    }

    public void setApplicationPic(String applicationPic) {
        this.applicationPic = applicationPic;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public String getApplicationDate() {
        return applicationDate;
    }

    public void setApplicationDate(String applicationDate) {
        this.applicationDate = applicationDate;
    }

    public Integer getApplicationState() {
        return applicationState;
    }

    public void setApplicationState(Integer applicationState) {
        this.applicationState = applicationState;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public Integer getGoodsId() {
        return goodsId;
    }

    public void setGoodsId(Integer goodsId) {
        this.goodsId = goodsId;
    }

    //逻辑视图
    public String getApplicationTypeStr(){
        if (applicationType == null){
            return "未知";
        }
        return applicationType == 1 ? "申请开店":"申请上架商品";
    }

    //逻辑视图
    public String getApplicationStateStr(){
        switch (applicationState){
            case 0:
                return "审核中";
            case 1:
                return "审核通过";
            case 2:
                return "审核未通过";
            default:
                return "未知";
        }
    }

    @Override
    public String toString() {
        return "Application{" +
                "applicationId=" + applicationId +
                ", applicationType=" + applicationType +
                ", applicationUserId=" + applicationUserId +
                ", applicationUserName='" + applicationUserName + '\'' +
                ", name='" + name + '\'' +
                ", applicationPic='" + applicationPic + '\'' +
                ", description='" + description + '\'' +
                ", applicationDate='" + applicationDate + '\'' +
                ", applicationState=" + applicationState +
                ", address='" + address + '\'' +
                ", goodsId=" + goodsId +
                '}';
    }
}
