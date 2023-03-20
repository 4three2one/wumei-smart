package com.ruoyi.iot.domain;

import org.apache.commons.lang3.builder.ToStringBuilder;
import org.apache.commons.lang3.builder.ToStringStyle;
import com.ruoyi.common.annotation.Excel;
import com.ruoyi.common.core.domain.BaseEntity;

/**
 * 识别分析对象 recog_analysis
 *
 * @author xujiawei
 * @date 2023-03-19
 */
public class RecogAnalysis extends BaseEntity
{
    private static final long serialVersionUID = 1L;

    /** ID */
    private Long recogId;

    /** 叶片类别 */
    @Excel(name = "叶片类别")
    private String leafName;

    /** 图片名称 */
    @Excel(name = "图片名称")
    private String imgName;

    /** 是否识别（0代表未识别 ） */
    @Excel(name = "是否识别", readConverterExp = "0=代表未识别")
    private String recogFlag;

    /** 产品名称 */
    @Excel(name = "产品名称")
    private String diseaseName;

    /** 删除标志（0代表存在 2代表删除） */
    private String delFlag;

    /** 模型名称 */
    @Excel(name = "模型名称")
    private String modelName;

    /** 准确率 */
    @Excel(name = "准确率")
    private Long recogProb;

    /** 用时 */
    @Excel(name = "用时")
    private Long timeUsing;

    /** 图片地址 */
    @Excel(name = "图片地址")
    private String imgUrl;

    /** 模型ID */
    @Excel(name = "模型ID")
    private Long modelId;

    public void setRecogId(Long recogId)
    {
        this.recogId = recogId;
    }

    public Long getRecogId()
    {
        return recogId;
    }
    public void setLeafName(String leafName)
    {
        this.leafName = leafName;
    }

    public String getLeafName()
    {
        return leafName;
    }
    public void setImgName(String imgName)
    {
        this.imgName = imgName;
    }

    public String getImgName()
    {
        return imgName;
    }
    public void setRecogFlag(String recogFlag)
    {
        this.recogFlag = recogFlag;
    }

    public String getRecogFlag()
    {
        return recogFlag;
    }
    public void setDiseaseName(String diseaseName)
    {
        this.diseaseName = diseaseName;
    }

    public String getDiseaseName()
    {
        return diseaseName;
    }
    public void setDelFlag(String delFlag)
    {
        this.delFlag = delFlag;
    }

    public String getDelFlag()
    {
        return delFlag;
    }
    public void setModelName(String modelName)
    {
        this.modelName = modelName;
    }

    public String getModelName()
    {
        return modelName;
    }
    public void setRecogProb(Long recogProb)
    {
        this.recogProb = recogProb;
    }

    public Long getRecogProb()
    {
        return recogProb;
    }
    public void setTimeUsing(Long timeUsing)
    {
        this.timeUsing = timeUsing;
    }

    public Long getTimeUsing()
    {
        return timeUsing;
    }
    public void setImgUrl(String imgUrl)
    {
        this.imgUrl = imgUrl;
    }

    public String getImgUrl()
    {
        return imgUrl;
    }
    public void setModelId(Long modelId)
    {
        this.modelId = modelId;
    }

    public Long getModelId()
    {
        return modelId;
    }

    @Override
    public String toString() {
        return new ToStringBuilder(this,ToStringStyle.MULTI_LINE_STYLE)
                .append("recogId", getRecogId())
                .append("leafName", getLeafName())
                .append("imgName", getImgName())
                .append("recogFlag", getRecogFlag())
                .append("diseaseName", getDiseaseName())
                .append("delFlag", getDelFlag())
                .append("createBy", getCreateBy())
                .append("createTime", getCreateTime())
                .append("updateBy", getUpdateBy())
                .append("updateTime", getUpdateTime())
                .append("remark", getRemark())
                .append("modelName", getModelName())
                .append("recogProb", getRecogProb())
                .append("timeUsing", getTimeUsing())
                .append("imgUrl", getImgUrl())
                .append("modelId", getModelId())
                .toString();
    }
}