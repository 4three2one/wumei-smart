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
import com.ruoyi.iot.domain.RecogModel;
import com.ruoyi.iot.service.IRecogModelService;
import com.ruoyi.common.utils.poi.ExcelUtil;
import com.ruoyi.common.core.page.TableDataInfo;

/**
 * 模型名称Controller
 *
 * @author xujiawei
 * @date 2023-03-19
 */
@RestController
@RequestMapping("/recog/model")
public class RecogModelController extends BaseController
{
    @Autowired
    private IRecogModelService recogModelService;

    /**
     * 查询模型名称列表
     */
    @PreAuthorize("@ss.hasPermi('recog:model:list')")
    @GetMapping("/list")
    public TableDataInfo list(RecogModel recogModel)
    {
        startPage();
        List<RecogModel> list = recogModelService.selectRecogModelList(recogModel);
        return getDataTable(list);
    }

    /**
     * 导出模型名称列表
     */
    @PreAuthorize("@ss.hasPermi('recog:model:export')")
    @Log(title = "模型名称", businessType = BusinessType.EXPORT)
    @PostMapping("/export")
    public void export(HttpServletResponse response, RecogModel recogModel)
    {
        List<RecogModel> list = recogModelService.selectRecogModelList(recogModel);
        ExcelUtil<RecogModel> util = new ExcelUtil<RecogModel>(RecogModel.class);
        util.exportExcel(response, list, "模型名称数据");
    }

    /**
     * 获取模型名称详细信息
     */
    @PreAuthorize("@ss.hasPermi('recog:model:query')")
    @GetMapping(value = "/{modelId}")
    public AjaxResult getInfo(@PathVariable("modelId") Long modelId)
    {
        return AjaxResult.success(recogModelService.selectRecogModelByModelId(modelId));
    }

    /**
     * 新增模型名称
     */
    @PreAuthorize("@ss.hasPermi('recog:model:add')")
    @Log(title = "模型名称", businessType = BusinessType.INSERT)
    @PostMapping
    public AjaxResult add(@RequestBody RecogModel recogModel)
    {
        return toAjax(recogModelService.insertRecogModel(recogModel));
    }

    /**
     * 修改模型名称
     */
    @PreAuthorize("@ss.hasPermi('recog:model:edit')")
    @Log(title = "模型名称", businessType = BusinessType.UPDATE)
    @PutMapping
    public AjaxResult edit(@RequestBody RecogModel recogModel)
    {
        return toAjax(recogModelService.updateRecogModel(recogModel));
    }

    /**
     * 删除模型名称
     */
    @PreAuthorize("@ss.hasPermi('recog:model:remove')")
    @Log(title = "模型名称", businessType = BusinessType.DELETE)
    @DeleteMapping("/{modelIds}")
    public AjaxResult remove(@PathVariable Long[] modelIds)
    {
        return toAjax(recogModelService.deleteRecogModelByModelIds(modelIds));
    }
}