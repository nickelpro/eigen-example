#include <Eigen/Eigen>

namespace lib {

int add(int a, int b) {
  return Eigen::RowVector2i {a, b}.sum();
}

} // namespace lib
