using BenchmarkTools

v_x(x, y, t,C) = -sin(pi * y) * cos(pi * t / C)
v_y(x, y, t,C) =  sin(pi * x) * cos(pi * t / C)
#Don't forget to pass in C using the parameters argument
function rhs!(du, u, parameters, t) 
    num_particles = size(u, 2)
    for i in 1:num_particles
        du[1, i] = v_x(u[1, i], u[2, i], t,parameters)
        du[2, i] = v_y(u[1, i], u[2, i], t,parameters)
    end
end

@btime rhs!
#It's allocation free
# @btime rhs!
#   1.700 ns (0 allocations: 0 bytes)
# rhs! (generic function with 1 method)