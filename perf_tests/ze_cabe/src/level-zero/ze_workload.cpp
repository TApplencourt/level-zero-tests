/*
 *
 * Copyright (C) 2020 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "ze_workload.hpp"

namespace compute_api_bench {

ZeWorkload::ZeWorkload() : Workload() { workload_api = "Level-Zero"; }

ZeWorkload::~ZeWorkload() {}

void ZeWorkload::create_device() {
  ZE_CHECK_RESULT(zeInit(ZE_INIT_FLAG_NONE));

  uint32_t driverCount = 0;
  ZE_CHECK_RESULT(zeDriverGet(&driverCount, nullptr));
  if (driverCount == 0)
    std::terminate();
  ZE_CHECK_RESULT(zeDriverGet(&driverCount, &driver_handle));

  uint32_t device_count = 0;
  ZE_CHECK_RESULT(zeDeviceGet(driver_handle, &device_count, nullptr));
  if (device_count == 0)
    std::terminate();
  device_count = 1;
  ZE_CHECK_RESULT(zeDeviceGet(driver_handle, &device_count, &device));
}

void ZeWorkload::prepare_program() {}

} // namespace compute_api_bench