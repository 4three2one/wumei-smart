<template>
  <div class="app-container">
<!--    <el-form :model="queryParams" ref="queryForm" :inline="true" v-show="showSearch" label-width="68px">
      <el-form-item label="叶片类别" prop="leafName">
        <el-input
          v-model="queryParams.leafName"
          placeholder="请输入叶片类别"
          clearable
          size="small"
          @keyup.enter.native="handleQuery"
        />
      </el-form-item>
      <el-form-item label="是否识别" prop="recogFlag">
        <el-input
          v-model="queryParams.recogFlag"
          placeholder="请输入是否识别"
          clearable
          size="small"
          @keyup.enter.native="handleQuery"
        />
      </el-form-item>
      <el-form-item label="产品名称" prop="diseaseName">
        <el-input
          v-model="queryParams.diseaseName"
          placeholder="请输入产品名称"
          clearable
          size="small"
          @keyup.enter.native="handleQuery"
        />
      </el-form-item>
      <el-form-item label="模型名称" prop="modelName">
        <el-select v-model="queryParams.modelName" placeholder="请选择模型名称" clearable size="small">
          <el-option
            v-for="dict in dict.type.recog_model_name"
            :key="dict.value"
            :label="dict.label"
            :value="dict.value"
          />
        </el-select>
      </el-form-item>
      <el-form-item label="准确率" prop="recogProb">
        <el-input
          v-model="queryParams.recogProb"
          placeholder="请输入准确率"
          clearable
          size="small"
          @keyup.enter.native="handleQuery"
        />
      </el-form-item>
      <el-form-item label="用时" prop="timeUsing">
        <el-input
          v-model="queryParams.timeUsing"
          placeholder="请输入用时"
          clearable
          size="small"
          @keyup.enter.native="handleQuery"
        />
      </el-form-item>
      <el-form-item label="图片地址" prop="imgUrl">
        <el-input
          v-model="queryParams.imgUrl"
          placeholder="请输入图片地址"
          clearable
          size="small"
          @keyup.enter.native="handleQuery"
        />
      </el-form-item>
      <el-form-item label="模型ID" prop="modelId">
        <el-input
          v-model="queryParams.modelId"
          placeholder="请输入模型ID"
          clearable
          size="small"
          @keyup.enter.native="handleQuery"
        />
      </el-form-item>
      <el-form-item>
        <el-button type="primary" icon="el-icon-search" size="mini" @click="handleQuery">搜索</el-button>
        <el-button icon="el-icon-refresh" size="mini" @click="resetQuery">重置</el-button>
      </el-form-item>
    </el-form>-->

    <el-row :gutter="10" class="mb8">
      <el-col :span="1.5">
        <el-button
          type="primary"
          plain
          icon="el-icon-plus"
          size="mini"
          @click="handleAdd"
          v-hasPermi="['recog:analysis:add']"
        >新增</el-button>
      </el-col>
      <el-col :span="1.5">
        <el-button
          type="success"
          plain
          icon="el-icon-edit"
          size="mini"
          :disabled="single"
          @click="handleUpdate"
          v-hasPermi="['recog:analysis:edit']"
        >修改</el-button>
      </el-col>
      <el-col :span="1.5">
        <el-button
          type="danger"
          plain
          icon="el-icon-delete"
          size="mini"
          :disabled="multiple"
          @click="handleDelete"
          v-hasPermi="['recog:analysis:remove']"
        >删除</el-button>
      </el-col>
      <el-col :span="1.5">
        <el-button
          type="warning"
          plain
          icon="el-icon-download"
          size="mini"
          @click="handleExport"
          v-hasPermi="['recog:analysis:export']"
        >导出</el-button>
      </el-col>
      <right-toolbar :showSearch.sync="showSearch" @queryTable="getList"></right-toolbar>
    </el-row>

    <el-card style="padding-bottom:100px;" v-loading="loading" @selection-change="handleSelectionChange">
      <el-row :gutter="40" >
        <el-col  :xs="24" :sm="12" :md="12" :lg="8" :xl="6" v-for="(item,index) in analysisList" :key="index" style="margin-bottom:30px;text-align:center;">
          <el-card :body-style="{ padding: '20px'}" shadow="always" class="card-item">
            <el-row :gutter="10" >
              <el-col :span="12" style="margin-top:30px;">
                <el-descriptions :column="1" size="small" style="margin-top:10px;white-space:nowrap;">
                  <el-descriptions-item label="图片名称">
                        {{item.leafName}}
                  </el-descriptions-item>
                  <el-descriptions-item label="识别模型">
                    {{item.modelName}}
                  </el-descriptions-item>
                  <el-descriptions-item label="识别结果">
                    {{item.diseaseName}}
                  </el-descriptions-item>
<!--                  <el-descriptions-item label="识别概率">-->
<!--                    <dict-tag :options="dict.type.iot_network_method" :value="item.recogProb" />-->
<!--                  </el-descriptions-item>-->

                </el-descriptions>
              </el-col>
              <el-col :span="12">
                <div style="margin-top:10px;">
                  <el-image style="width:150px;height:150px;border-radius:10px" lazy :preview-src-list="[require('@/assets/images/'+item.imgUrl)]" :src="[require('@/assets/images/'+item.imgUrl)]" fit="cover" v-if="item.imgUrl!=null && item.imgUrl!=''"></el-image>
                  <el-image style="width:200px;height:200px;border-radius:10px;" :preview-src-list="[require('@/assets/images/leaf_health.jpg')]" :src="require('@/assets/images/leaf_health.jpg')" fit="cover" v-else></el-image>
                </div>
              </el-col>
            </el-row>
          </el-card>
        </el-col>
      </el-row>
<!--      <el-table-column type="selection" width="55" align="center" />-->
<!--      <el-table-column label="ID" align="center" prop="recogId" />-->
<!--      <el-table-column label="叶片类别" align="center" prop="leafName" />-->
<!--      <el-table-column label="图片名称" align="center" prop="imgName" />-->
<!--      <el-table-column label="是否识别" align="center" prop="recogFlag" />-->
<!--      <el-table-column label="产品名称" align="center" prop="diseaseName" />-->
<!--      <el-table-column label="备注" align="center" prop="remark" />-->
<!--      <el-table-column label="模型名称" align="center" prop="modelName">-->
<!--        <template slot-scope="scope">-->
<!--          <dict-tag :options="dict.type.recog_model_name" :value="scope.row.modelName"/>-->
<!--        </template>-->
<!--      </el-table-column>-->
<!--      <el-table-column label="准确率" align="center" prop="recogProb" />-->
<!--      <el-table-column label="用时" align="center" prop="timeUsing" />-->
<!--      <el-table-column label="图片地址" align="center" prop="imgUrl" />-->
<!--      <el-table-column label="模型ID" align="center" prop="modelId" />-->
<!--      <el-table-column label="操作" align="center" class-name="small-padding fixed-width">-->
<!--        <template slot-scope="scope">-->
<!--          <el-button-->
<!--            size="mini"-->
<!--            type="text"-->
<!--            icon="el-icon-edit"-->
<!--            @click="handleUpdate(scope.row)"-->
<!--            v-hasPermi="['recog:analysis:edit']"-->
<!--          >修改</el-button>-->
<!--          <el-button-->
<!--            size="mini"-->
<!--            type="text"-->
<!--            icon="el-icon-delete"-->
<!--            @click="handleDelete(scope.row)"-->
<!--            v-hasPermi="['recog:analysis:remove']"-->
<!--          >删除</el-button>-->
<!--        </template>-->
<!--      </el-table-column>-->
    </el-card>

    <pagination
      v-show="total>0"
      :total="total"
      :page.sync="queryParams.pageNum"
      :limit.sync="queryParams.pageSize"
      @pagination="getList"
    />

    <!-- 添加或修改识别分析对话框 -->
    <el-dialog :title="title" :visible.sync="open" width="500px" append-to-body>
      <el-form ref="form" :model="form" :rules="rules" label-width="80px">
        <el-form-item label="图片名称" prop="leafName">
          <el-input v-model="form.leafName" placeholder="请输入叶片类别" />
        </el-form-item>
        <el-form-item label="图片路径">
          <imageUpload v-model="form.imgName"/>
        </el-form-item>
<!--        <el-form-item label="是否识别" prop="recogFlag">
          <el-input v-model="form.recogFlag" placeholder="请输入是否识别" />
        </el-form-item>
        <el-form-item label="产品名称" prop="diseaseName">
          <el-input v-model="form.diseaseName" placeholder="请输入产品名称" />
        </el-form-item>
        <el-form-item label="删除标志" prop="delFlag">
          <el-input v-model="form.delFlag" placeholder="请输入删除标志" />
        </el-form-item>
        <el-form-item label="备注" prop="remark">
          <el-input v-model="form.remark" type="textarea" placeholder="请输入内容" />
        </el-form-item>-->
        <el-form-item label="模型名称" prop="modelName">
          <el-select v-model="form.modelName" placeholder="请选择模型名称">
            <el-option
              v-for="dict in dict.type.recog_model_name"
              :key="dict.value"
              :label="dict.label"
              :value="dict.value"
            ></el-option>
          </el-select>
        </el-form-item>
        <el-form-item label="备注" prop="remark">
          <el-input v-model="form.remark" type="textarea" placeholder="请输入内容" />
        </el-form-item>
<!--        <el-form-item label="准确率" prop="recogProb">
          <el-input v-model="form.recogProb" placeholder="请输入准确率" />
        </el-form-item>
        <el-form-item label="用时" prop="timeUsing">
          <el-input v-model="form.timeUsing" placeholder="请输入用时" />
        </el-form-item>
        <el-form-item label="图片地址" prop="imgUrl">
          <el-input v-model="form.imgUrl" placeholder="请输入图片地址" />
        </el-form-item>
        <el-form-item label="模型ID" prop="modelId">
          <el-input v-model="form.modelId" placeholder="请输入模型ID" />
        </el-form-item>-->
      </el-form>
      <div slot="footer" class="dialog-footer">
        <el-button type="primary" @click="submitForm">确 定</el-button>
        <el-button @click="cancel">取 消</el-button>
      </div>
    </el-dialog>
  </div>
</template>

<script>
import { listAnalysis, getAnalysis, delAnalysis, addAnalysis, updateAnalysis } from "@/api/recog/analysis";

export default {
  name: "Analysis",
  dicts: ['recog_model_name'],
  data() {
    return {
      // 遮罩层
      loading: true,
      // 选中数组
      ids: [],
      // 非单个禁用
      single: true,
      // 非多个禁用
      multiple: true,
      // 显示搜索条件
      showSearch: true,
      // 总条数
      total: 0,
      // 识别分析表格数据
      analysisList: [],
      // 弹出层标题
      title: "",
      // 是否显示弹出层
      open: false,
      // 查询参数
      queryParams: {
        pageNum: 1,
        pageSize: 10,
        leafName: null,
        imgName: null,
        recogFlag: null,
        diseaseName: null,
        modelName: null,
        recogProb: null,
        timeUsing: null,
        imgUrl: null,
        modelId: null
      },
      // 表单参数
      form: {},
      // 表单校验
      rules: {
        leafName: [
          { required: true, message: "叶片类别不能为空", trigger: "blur" }
        ],
        imgName: [
          { required: true, message: "图片名称不能为空", trigger: "blur" }
        ],
      }
    };
  },
  created() {
    this.getList();
  },
  methods: {
    /** 查询识别分析列表 */
    getList() {
      this.loading = true;
      listAnalysis(this.queryParams).then(response => {
        this.analysisList = response.rows;
        this.total = response.total;
        this.loading = false;
      });
    },
    // 取消按钮
    cancel() {
      this.open = false;
      this.reset();
    },
    // 表单重置
    reset() {
      this.form = {
        recogId: null,
        leafName: null,
        imgName: null,
        recogFlag: null,
        diseaseName: null,
        delFlag: null,
        createBy: null,
        createTime: null,
        updateBy: null,
        updateTime: null,
        remark: null,
        modelName: null,
        recogProb: null,
        timeUsing: null,
        imgUrl: null,
        modelId: null
      };
      this.resetForm("form");
    },
    /** 搜索按钮操作 */
    handleQuery() {
      this.queryParams.pageNum = 1;
      this.getList();
    },
    /** 重置按钮操作 */
    resetQuery() {
      this.resetForm("queryForm");
      this.handleQuery();
    },
    // 多选框选中数据
    handleSelectionChange(selection) {
      this.ids = selection.map(item => item.recogId)
      this.single = selection.length!==1
      this.multiple = !selection.length
    },
    /** 新增按钮操作 */
    handleAdd() {
      this.reset();
      this.open = true;
      this.title = "添加识别分析";
    },
    /** 修改按钮操作 */
    handleUpdate(row) {
      this.reset();
      const recogId = row.recogId || this.ids
      getAnalysis(recogId).then(response => {
        this.form = response.data;
        this.open = true;
        this.title = "修改识别分析";
      });
    },
    /** 提交按钮 */
    submitForm() {
      this.$refs["form"].validate(valid => {
        if (valid) {
          if (this.form.recogId != null) {
            updateAnalysis(this.form).then(response => {
              this.$modal.msgSuccess("修改成功");
              this.open = false;
              this.getList();
            });
          } else {
            addAnalysis(this.form).then(response => {
              this.$modal.msgSuccess("新增成功");
              this.open = false;
              this.getList();
            });
          }
        }
      });
    },
    /** 删除按钮操作 */
    handleDelete(row) {
      const recogIds = row.recogId || this.ids;
      this.$modal.confirm('是否确认删除识别分析编号为"' + recogIds + '"的数据项？').then(function() {
        return delAnalysis(recogIds);
      }).then(() => {
        this.getList();
        this.$modal.msgSuccess("删除成功");
      }).catch(() => {});
    },
    /** 导出按钮操作 */
    handleExport() {
      this.download('recog/analysis/export', {
        ...this.queryParams
      }, `analysis_${new Date().getTime()}.xlsx`)
    }
  }
};
</script>
