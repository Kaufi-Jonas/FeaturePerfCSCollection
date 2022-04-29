#include "fpcsc/perf_util/feature_cmd.h"
#include "fpcsc/perf_util/sleep.h"

typedef struct {
  bool slow1;
  bool slow2;
} Config;

int main(int argc, char *argv[]) {
  Config config;
  config.slow1 = fpcsc::isFeatureEnabled(argc, argv, "--slow1");
  config.slow2 = fpcsc::isFeatureEnabled(argc, argv, "--slow2");

  if (config.slow1) {
    fpcsc::sleep_for_secs(5);
  } else {
    fpcsc::sleep_for_secs(2);
  }

  fpcsc::sleep_for_secs(3); // General waiting time

  if (config.slow2) {
    fpcsc::sleep_for_secs(3);
  } else {
    fpcsc::sleep_for_secs(1);
  }

  fpcsc::sleep_for_secs(4); // General waiting time

  return 0;
}
