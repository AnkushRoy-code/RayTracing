# Spheres
The mathematical definition of spheres are simple its:

```maths
x^2 + y^2 + z^2 = r^2
```

Where 'r' is radius

This sphere is in the center. If we want to translate this sphere to somewhere then we have to do this:

Let C be the center of the sphere. Then the equation becomes

```maths
(C.x - x)^2 + (C.y - y)^2 + (C.z -z)^2 = r^2
```

It is not good looking so we do some maths.

If we do dot Product of (C - P) and (C - P), we get:

```maths
(C.x - x)^2 + (C.y - y)^2 + (C.z -z)^2 
```

So we can easily do this instead:
```maths
(C - P) ⋅ (C - P) = r^2
```

In the equation we have P = P(t) from Ray.md

This becomes:
```maths
(C - P(t)) ⋅ (C - P(t)) = r^2
```

Expanding we have:
```maths
(C - (A + td)) ⋅ (C - (A + td) = r^2
=> (−td + (C − A)) ⋅ (−td + (C − A)) = r^2
=> t^2 * d⋅d - 2t * d⋅(C - A) + (C - A)⋅(C - A) = r^2
=> t^2 * d⋅d - 2t * d⋅(C - A) + (C - A)⋅(C - A) - r^2 = 0
```
Boom we have a quadratic in t now

Using Sri Dharachariya we get.

a = d⋅d
b = -2d⋅(C - A)
c = (C - A) ⋅ (C - A) - r^2

If discriminant of the quadratic is positive we have 2 real solutions -> intersecting the circle.
If discriminant of the quadratic is negetive we have 0 real solutions -> not passing the circle.
If discriminant of the quadratic is 0 we have 1 real solutions -> tangent to the circle.

We can further optimise this.

```maths

−b ± √(b^2 − 4ac) / 2a

let b = -2h

= −(−2h) ± √((−2h)^2 − 4ac) / 2a

= 2h ± √(4h^2 − 4ac) / 2a

= h ± √(h^2 − ac) / a
```

This has gotten better so we can use it...

```maths
b = −2d ⋅ (C − Q)  
b = −2h  
h = b / −2 = d ⋅ (C − Q)

```
