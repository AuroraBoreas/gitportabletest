#include <math.h>

#define E 2.718

/// @brief Calculate the reliability
/// @param t is the observed service life (h, for example)
/// @param mtbf mtbf is the failure times (x, for example)
/// @return Reliability
double reliability(double t, double mtbf) {
  return pow(E,-t/mtbf);
}

/// @brief An exponential distribution `F(t) = 1 - e^{-λt}` is used to define the probability of failure of electronic and electromechanical components.
/// @remark This correlation applies only for the phase of constant failure rate in the bathtub curve, i.e. for λ = constant
/// @param t  is the observed service life (h, for example)
/// @param λ is the failure rate in 1/time unit (1/h, for example)
/// @return Probability of failure
double pof(double t, double λ) {
  return 1 - pow(E, -λ * t);
}

/// @brief calculate MTBF is the inverse of failure rate
/// @param λ fail in time
/// @return Mean Time between Failure
double mtbf(double λ) {
  return 1 / λ;
}

double fit(double mtbf) {
  return 1 / mtbf;
}

/// @brief Calculate the exponential distribution
/// @param t is the observed service life (h, for example)
/// @param mtbf is the failure times (x, for example)
/// @return probability of failure
double pof2(double t, double mtbf) {
  return 1 - pow(E, -t / mtbf);
}

/// @brief Accelerated Aging Formula: Shelf Life Aging Formula,  is commonly used in the medical device industry to accelerate the effects of time on a Sterile Barrier System to establish Shelf Life parameters. The Accelerated Aging process is based on the relationship of temperature and reaction rate where an increase in temperature increases the reaction rate.
/// @param rt Real Time (or Target Shelf Life Days): An estimate of the product's shelf life.
/// @param taa Accelerated Aging Temperature: Common TAAs are +50ºC, +55ºC, and +60ºC. Does not recommend aging packaging materials at temperatures exceeding +60ºC
/// @param trt Ambient Temperature (TRT): Ambient temperature is typically between +20ºC to +25ºC. A temperature of +25ºC is a more conservative approach.
/// @param q10 The aging factor is typically between 1.8 – 2.5 with a value of 2.0 being the most common value.
/// @return Accelerated Aging Time(AAT): The number of days of testing required.
double aat(unsigned rt, float taa, float trt, float q10) {
  return ceil(rt/(pow(q10, (taa - trt)/10)));
}