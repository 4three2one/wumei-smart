package com.ruoyi.iot.service;

import java.util.List;
import com.ruoyi.iot.domain.RecogAnalysis;

/**
 * 识别分析Service接口
 *
 * @author xujiawei
 * @date 2023-03-19
 */
public interface IRecogAnalysisService
{
    /**
     * 查询识别分析
     *
     * @param recogId 识别分析主键
     * @return 识别分析
     */
    public RecogAnalysis selectRecogAnalysisByRecogId(Long recogId);

    /**
     * 查询识别分析列表
     *
     * @param recogAnalysis 识别分析
     * @return 识别分析集合
     */
    public List<RecogAnalysis> selectRecogAnalysisList(RecogAnalysis recogAnalysis);

    /**
     * 新增识别分析
     *
     * @param recogAnalysis 识别分析
     * @return 结果
     */
    public int insertRecogAnalysis(RecogAnalysis recogAnalysis);

    /**
     * 修改识别分析
     *
     * @param recogAnalysis 识别分析
     * @return 结果
     */
    public int updateRecogAnalysis(RecogAnalysis recogAnalysis);

    /**
     * 批量删除识别分析
     *
     * @param recogIds 需要删除的识别分析主键集合
     * @return 结果
     */
    public int deleteRecogAnalysisByRecogIds(Long[] recogIds);

    /**
     * 删除识别分析信息
     *
     * @param recogId 识别分析主键
     * @return 结果
     */
    public int deleteRecogAnalysisByRecogId(Long recogId);
}