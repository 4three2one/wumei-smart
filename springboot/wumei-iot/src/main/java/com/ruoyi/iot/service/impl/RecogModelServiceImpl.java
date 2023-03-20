package com.ruoyi.iot.service.impl;

import java.util.List;
import com.ruoyi.common.utils.DateUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import com.ruoyi.iot.mapper.RecogModelMapper;
import com.ruoyi.iot.domain.RecogModel;
import com.ruoyi.iot.service.IRecogModelService;

/**
 * 模型名称Service业务层处理
 *
 * @author xujiawei
 * @date 2023-03-19
 */
@Service
public class RecogModelServiceImpl implements IRecogModelService
{
    @Autowired
    private RecogModelMapper recogModelMapper;

    /**
     * 查询模型名称
     *
     * @param modelId 模型名称主键
     * @return 模型名称
     */
    @Override
    public RecogModel selectRecogModelByModelId(Long modelId)
    {
        return recogModelMapper.selectRecogModelByModelId(modelId);
    }

    /**
     * 查询模型名称列表
     *
     * @param recogModel 模型名称
     * @return 模型名称
     */
    @Override
    public List<RecogModel> selectRecogModelList(RecogModel recogModel)
    {
        return recogModelMapper.selectRecogModelList(recogModel);
    }

    /**
     * 新增模型名称
     *
     * @param recogModel 模型名称
     * @return 结果
     */
    @Override
    public int insertRecogModel(RecogModel recogModel)
    {
        recogModel.setCreateTime(DateUtils.getNowDate());
        return recogModelMapper.insertRecogModel(recogModel);
    }

    /**
     * 修改模型名称
     *
     * @param recogModel 模型名称
     * @return 结果
     */
    @Override
    public int updateRecogModel(RecogModel recogModel)
    {
        recogModel.setUpdateTime(DateUtils.getNowDate());
        return recogModelMapper.updateRecogModel(recogModel);
    }

    /**
     * 批量删除模型名称
     *
     * @param modelIds 需要删除的模型名称主键
     * @return 结果
     */
    @Override
    public int deleteRecogModelByModelIds(Long[] modelIds)
    {
        return recogModelMapper.deleteRecogModelByModelIds(modelIds);
    }

    /**
     * 删除模型名称信息
     *
     * @param modelId 模型名称主键
     * @return 结果
     */
    @Override
    public int deleteRecogModelByModelId(Long modelId)
    {
        return recogModelMapper.deleteRecogModelByModelId(modelId);
    }
}