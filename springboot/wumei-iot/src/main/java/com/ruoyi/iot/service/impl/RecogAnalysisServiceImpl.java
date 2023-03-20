package com.ruoyi.iot.service.impl;

import java.util.List;
import com.ruoyi.common.utils.DateUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import com.ruoyi.iot.mapper.RecogAnalysisMapper;
import com.ruoyi.iot.domain.RecogAnalysis;
import com.ruoyi.iot.service.IRecogAnalysisService;

/**
 * 识别分析Service业务层处理
 *
 * @author xujiawei
 * @date 2023-03-19
 */
@Service
public class RecogAnalysisServiceImpl implements IRecogAnalysisService
{
    @Autowired
    private RecogAnalysisMapper recogAnalysisMapper;

    /**
     * 查询识别分析
     *
     * @param recogId 识别分析主键
     * @return 识别分析
     */
    @Override
    public RecogAnalysis selectRecogAnalysisByRecogId(Long recogId)
    {
        return recogAnalysisMapper.selectRecogAnalysisByRecogId(recogId);
    }

    /**
     * 查询识别分析列表
     *
     * @param recogAnalysis 识别分析
     * @return 识别分析
     */
    @Override
    public List<RecogAnalysis> selectRecogAnalysisList(RecogAnalysis recogAnalysis)
    {
        return recogAnalysisMapper.selectRecogAnalysisList(recogAnalysis);
    }

    /**
     * 新增识别分析
     *
     * @param recogAnalysis 识别分析
     * @return 结果
     */
    @Override
    public int insertRecogAnalysis(RecogAnalysis recogAnalysis)
    {
        recogAnalysis.setCreateTime(DateUtils.getNowDate());
        return recogAnalysisMapper.insertRecogAnalysis(recogAnalysis);
    }

    /**
     * 修改识别分析
     *
     * @param recogAnalysis 识别分析
     * @return 结果
     */
    @Override
    public int updateRecogAnalysis(RecogAnalysis recogAnalysis)
    {
        recogAnalysis.setUpdateTime(DateUtils.getNowDate());
        return recogAnalysisMapper.updateRecogAnalysis(recogAnalysis);
    }

    /**
     * 批量删除识别分析
     *
     * @param recogIds 需要删除的识别分析主键
     * @return 结果
     */
    @Override
    public int deleteRecogAnalysisByRecogIds(Long[] recogIds)
    {
        return recogAnalysisMapper.deleteRecogAnalysisByRecogIds(recogIds);
    }

    /**
     * 删除识别分析信息
     *
     * @param recogId 识别分析主键
     * @return 结果
     */
    @Override
    public int deleteRecogAnalysisByRecogId(Long recogId)
    {
        return recogAnalysisMapper.deleteRecogAnalysisByRecogId(recogId);
    }
}