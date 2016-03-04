template <typename FuncType,typename JacType,typename VecType>
void newton_stc(const FuncType &F,const JacType &DF,
	        VecType &x,double rtol,double atol)
{
  using scalar_t = typename VecType::Scalar;
  scalar_t sn;
  do {
    auto jacfac = DF(x).lu(); // LU-factorize Jacobian \Label[line]{nstc:1}]
    x -= jacfac.solve(F(x));  // Compute next iterate \Label[line]{nstc:2}
    // Compute norm of simplified Newton correction
    sn = jacfac.solve(F(x)).norm();
  }
  // Termination based on simplified Newton correction
  while ((sn > rtol*x.norm()) && (sn > atol));
}
