package com.ruoyi.iot.service;

import java.util.List;
import com.ruoyi.iot.domain.RecogModel;

/**
 * 模型名称Service接口
 *
 * @author xujiawei
 * @date 2023-03-19
 */
public interface IRecogModelService
{
    /**
     * 查询模型名称
     *
     * @param modelId 模型名称主键
     * @return 模型名称
     */
    public RecogModel selectRecogModelByModelId(Long modelId);

    /**
     * 查询模型名称列表
     *
     * @param recogModel 模型名称
     * @return 模型名称集合
     */
    public List<RecogModel> selectRecogModelList(RecogModel recogModel);

    /**
     * 新增模型名称
     *
     * @param recogModel 模型名称
     * @return 结果
     */
    public int insertRecogModel(RecogModel recogModel);

    /**
     * 修改模型名称
     *
     * @param recogModel 模型名称
     * @return 结果
     */
    public int updateRecogModel(RecogModel recogModel);

    /**
     * 批量删除模型名称
     *
     * @param modelIds 需要删除的模型名称主键集合
     * @return 结果
     */
    public int deleteRecogModelByModelIds(Long[] modelIds);

    /**
     * 删除模型名称信息
     *
     * @param modelId 模型名称主键
     * @return 结果
     */
    public int deleteRecogModelByModelId(Long modelId);
}