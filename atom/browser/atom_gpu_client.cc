// Copyright (c) 2019 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "atom/browser/atom_gpu_client.h"

#include "base/environment.h"

#if defined(OS_WIN)
#include <windows.h>
#endif

namespace atom {

AtomGpuClient::AtomGpuClient() = default;

void AtomGpuClient::PreCreateMainMessageLoop() {
#if defined(OS_WIN)
  auto env = base::Environment::Create();
  if (env->HasVar("ELECTRON_DEFAULT_ERROR_MODE"))
    SetErrorMode(GetErrorMode() & ~SEM_NOGPFAULTERRORBOX);
#endif
}

}  // namespace atom
