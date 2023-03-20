package com.ruoyi.iot.controller;

import java.util.List;
import javax.servlet.http.HttpServletResponse;
import org.springframework.security.access.prepost.PreAuthorize;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import com.ruoyi.common.annotation.Log;
import com.ruoyi.common.core.controller.BaseController;
import com.ruoyi.common.core.domain.AjaxResult;
import com.ruoyi.common.enums.BusinessType;
import com.ruoyi.iot.domain.RecogAnalysis;
import com.ruoyi.iot.service.IRecogAnalysisService;
import com.ruoyi.common.utils.poi.ExcelUtil;
import com.ruoyi.common.core.page.TableDataInfo;

/**
 * 识别分析Controller
 *
 * @author xujiawei
 * @date 2023-03-19
 */
@RestController
@RequestMapping("/recog/analysis")
public class RecogAnalysisController extends BaseController
{
    @Autowired
    private IRecogAnalysisService recogAnalysisService;

    /**
     * 查询识别分析列表
     */
    @PreAuthorize("@ss.hasPermi('recog:analysis:list')")
    @GetMapping("/list")
    public TableDataInfo list(RecogAnalysis recogAnalysis)
    {
        startPage();
        List<RecogAnalysis> list = recogAnalysisService.selectRecogAnalysisList(recogAnalysis);
        return getDataTable(list);
    }

    /**
     * 导出识别分析列表
     */
    @PreAuthorize("@ss.hasPermi('recog:analysis:export')")
    @Log(title = "识别分析", businessType = BusinessType.EXPORT)
    @PostMapping("/export")
    public void export(HttpServletResponse response, RecogAnalysis recogAnalysis)
    {
        List<RecogAnalysis> list = recogAnalysisService.selectRecogAnalysisList(recogAnalysis);
        ExcelUtil<RecogAnalysis> util = new ExcelUtil<RecogAnalysis>(RecogAnalysis.class);
        util.exportExcel(response, list, "识别分析数据");
    }

    /**
     * 获取识别分析详细信息
     */
    @PreAuthorize("@ss.hasPermi('recog:analysis:query')")
    @GetMapping(value = "/{recogId}")
    public AjaxResult getInfo(@PathVariable("recogId") Long recogId)
    {
        return AjaxResult.success(recogAnalysisService.selectRecogAnalysisByRecogId(recogId));
    }

    /**
     * 新增识别分析
     */
    @PreAuthorize("@ss.hasPermi('recog:analysis:add')")
    @Log(title = "识别分析", businessType = BusinessType.INSERT)
    @PostMapping
    public AjaxResult add(@RequestBody RecogAnalysis recogAnalysis)
    {
        return toAjax(recogAnalysisService.insertRecogAnalysis(recogAnalysis));
    }

    /**
     * 修改识别分析
     */
    @PreAuthorize("@ss.hasPermi('recog:analysis:edit')")
    @Log(title = "识别分析", businessType = BusinessType.UPDATE)
    @PutMapping
    public AjaxResult edit(@RequestBody RecogAnalysis recogAnalysis)
    {
        return toAjax(recogAnalysisService.updateRecogAnalysis(recogAnalysis));
    }

    /**
     * 删除识别分析
     */
    @PreAuthorize("@ss.hasPermi('recog:analysis:remove')")
    @Log(title = "识别分析", businessType = BusinessType.DELETE)
    @DeleteMapping("/{recogIds}")
    public AjaxResult remove(@PathVariable Long[] recogIds)
    {
        return toAjax(recogAnalysisService.deleteRecogAnalysisByRecogIds(recogIds));
    }
}