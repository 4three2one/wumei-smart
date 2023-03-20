package com.ruoyi.iot.domain;

import org.apache.commons.lang3.builder.ToStringBuilder;
import org.apache.commons.lang3.builder.ToStringStyle;
import com.ruoyi.common.annotation.Excel;
import com.ruoyi.common.core.domain.BaseEntity;

/**
 * 模型名称对象 recog_model
 *
 * @author xujiawei
 * @date 2023-03-19
 */
public class RecogModel extends BaseEntity
{
    private static final long serialVersionUID = 1L;

    /** 模型ID */
    private Long modelId;

    /** 模型名称 */
    @Excel(name = "模型名称")
    private String modelName;

    /** 模型状态（1-未激活，2-禁用，3-在线，4-离线） */
    @Excel(name = "模型状态", readConverterExp = "1=-未激活，2-禁用，3-在线，4-离线")
    private Integer status;

    /** 是否启用设备影子(0=禁用，1=启用) */
    @Excel(name = "是否启用设备影子(0=禁用，1=启用)")
    private Integer isShadow;

    /** 图片地址 */
    @Excel(name = "图片地址")
    private String imgUrl;

    /** 删除标志（0代表存在 2代表删除） */
    private String delFlag;

    public void setModelId(Long modelId)
    {
        this.modelId = modelId;
    }

    public Long getModelId()
    {
        return modelId;
    }
    public void setModelName(String modelName)
    {
        this.modelName = modelName;
    }

    public String getModelName()
    {
        return modelName;
    }
    public void setStatus(Integer status)
    {
        this.status = status;
    }

    public Integer getStatus()
    {
        return status;
    }
    public void setIsShadow(Integer isShadow)
    {
        this.isShadow = isShadow;
    }

    public Integer getIsShadow()
    {
        return isShadow;
    }
    public void setImgUrl(String imgUrl)
    {
        this.imgUrl = imgUrl;
    }

    public String getImgUrl()
    {
        return imgUrl;
    }
    public void setDelFlag(String delFlag)
    {
        this.delFlag = delFlag;
    }

    public String getDelFlag()
    {
        return delFlag;
    }

    @Override
    public String toString() {
        return new ToStringBuilder(this,ToStringStyle.MULTI_LINE_STYLE)
                .append("modelId", getModelId())
                .append("modelName", getModelName())
                .append("status", getStatus())
                .append("isShadow", getIsShadow())
                .append("imgUrl", getImgUrl())
                .append("delFlag", getDelFlag())
                .append("createBy", getCreateBy())
                .append("createTime", getCreateTime())
                .append("updateBy", getUpdateBy())
                .append("updateTime", getUpdateTime())
                .append("remark", getRemark())
                .toString();
    }
}