import request from '@/utils/request'

// 查询识别分析列表
export function listAnalysis(query) {
  return request({
    url: '/recog/analysis/list',
    method: 'get',
    params: query
  })
}

// 查询识别分析详细
export function getAnalysis(recogId) {
  return request({
    url: '/recog/analysis/' + recogId,
    method: 'get'
  })
}

// 新增识别分析
export function addAnalysis(data) {
  return request({
    url: '/recog/analysis',
    method: 'post',
    data: data
  })
}

// 修改识别分析
export function updateAnalysis(data) {
  return request({
    url: '/recog/analysis',
    method: 'put',
    data: data
  })
}

// 删除识别分析
export function delAnalysis(recogId) {
  return request({
    url: '/recog/analysis/' + recogId,
    method: 'delete'
  })
}
