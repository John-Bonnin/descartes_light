#ifndef DESCARTES_LIGHT_KINEMATICS_OPW_H
#define DESCARTES_LIGHT_KINEMATICS_OPW_H

#include <descartes_light/core/kinematics_interface.h>
#include <opw_kinematics/opw_kinematics.h>

namespace descartes_light
{

class OPWKinematics : public KinematicsInterface
{
public:
  OPWKinematics(const opw_kinematics::Parameters<double>& params,
                const Eigen::Isometry3d& world_to_base,
                const Eigen::Isometry3d& tool0_to_tip);

  bool ik(const Eigen::Isometry3d& p, std::vector<double>& solution_set) const override;
  bool fk(const double* pose, Eigen::Isometry3d& solution) const override;

private:
  opw_kinematics::Parameters<double> params_;
  Eigen::Isometry3d world_to_base_;
  Eigen::Isometry3d tool0_to_tip_;
};

}
#endif // DESCARTES_LIGHT_KINEMATICS_OPW_H
