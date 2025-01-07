#ifndef INCLUDE_SRC_INTERVAL_H_
#define INCLUDE_SRC_INTERVAL_H_

class interval
{
public:
    double min, max;

    interval();
    interval(double min, double max);

    [[nodiscard]] double size() const;
    [[nodiscard]] bool contains(double x) const;
    [[nodiscard]] bool surrounds(double x) const;

    static const interval empty, universe;
};

#endif  // INCLUDE_SRC_INTERVAL_H_
