import request from '@/utils/request'

// 查询模型名称列表
export function listModel(query) {
  return request({
    url: '/recog/model/list',
    method: 'get',
    params: query
  })
}

// 查询模型名称详细
export function getModel(modelId) {
  return request({
    url: '/recog/model/' + modelId,
    method: 'get'
  })
}

// 新增模型名称
export function addModel(data) {
  return request({
    url: '/recog/model',
    method: 'post',
    data: data
  })
}

// 修改模型名称
export function updateModel(data) {
  return request({
    url: '/recog/model',
    method: 'put',
    data: data
  })
}

// 删除模型名称
export function delModel(modelId) {
  return request({
    url: '/recog/model/' + modelId,
    method: 'delete'
  })
}
