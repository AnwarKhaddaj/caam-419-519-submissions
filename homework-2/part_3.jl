include("part_1.jl")
include("part_2.jl")

using LinearAlgebra
using Plots

num_particles=100;
FinalTime = 5;
dt = 1/1024
u = 0.1 .+ .45 * rand(2, num_particles)
u0=copy(u) #original copy

tspan=(0,FinalTime);
parameters=5;

#Verifying that rhs! is type stable
@code_warntype rhs!(u,u,1.0,1.0)
#Verifying that "solve" function is type stable
@code_warntype solve(ForwardEuler(),u,rhs!,tspan,1.0,1.0,; num_saved_steps=200)
@code_warntype solve(ExplicitMidpoint(u),u,rhs!,tspan,1.0,1.0,; num_saved_steps=200)

dt = [1/16, 1/32, 1/64, 1/128, 1/256, 1/512, 1/1024]
error_eul=zeros(7,1)
error_mid=zeros(7,1)
nbofeval_eul=zeros(7,1)
nbofeval_mid=zeros(7,1)
for i in 1:length(dt)
    u=copy(u0)
    u_store=solve(ForwardEuler(), u, rhs!, tspan, dt[i], parameters)
    error_eul[i]=norm(u-u0,2)
    nbofeval_eul[i]=u_store[2]

    u = copy(u0);
    u_store=solve(ExplicitMidpoint(u), u, rhs!, tspan, dt[i], parameters)
    error_mid[i]=norm(u-u0,2)
    nbofeval_mid[i]=u_store[2]
end

p1=plot()
plot!(p1,error_eul,dt,xaxis=:log,yaxis=:log,label="Euler Method Error")
plot!(p1,error_mid,dt,xaxis=:log,yaxis=:log,label="Explicit Method Error")
xlabel!(p1,"Error")
ylabel!(p1,"Timestep Size")
title!(p1, "Error vs timestep size dt")
savefig("plot1.png")


p2=plot()
plot!(p2,error_eul,nbofeval_eul,xaxis=:log,yaxis=:log,label="Euler Method Error")
plot!(p2,error_mid,nbofeval_mid,xaxis=:log,yaxis=:log,label="Explicit Method Error")
xlabel!(p2,"Error")
ylabel!(p2,"Number of rhs! evaluations")
title!(p2, "Error vs Number of rhs! evaluations")
savefig("plot2.png")

#PART 3: GIF ANIMATION

dt=1/1024
tspan=(0,10);
#Note that u_store_eul and u_store_mid will have u_store and counteval
#This is why I called u_store_eul[1] to get u_store below
u=copy(u0)
u_store_eul=solve(ForwardEuler(), u, rhs!, tspan, dt, parameters; num_saved_steps=200);
u=copy(u0)
u_store_mid=solve(ExplicitMidpoint(u), u, rhs!, tspan, dt, parameters; num_saved_steps=200);
# Nsteps = ceil(Int, (tspan[2]-tspan[1]) / dt)
#gif for Euler
anim=@animate for i=1:2:(Int)(size(u_store_eul[1],1))
    x=u_store_eul[1][i,:]
    y=u_store_eul[1][i+1,:]
    p3 = plot()
    scatter!(p3,x,y,xlims=(-1,1.5),ylims=(-1,2))
    plot!(p3)
    xlabel!(p3,"x")
    ylabel!(p3,"y")
    title!("Solution evolution for Euler's method")
end
gif(anim,"EulerMethod.gif")
#gif for Explicit 
anim=@animate for i=1:2:(Int)(size(u_store_mid[1],1))
    x=u_store_mid[1][i,:]
    y=u_store_mid[1][i+1,:]
    p4 = plot()
    scatter!(p4,x,y,xlims=(-1,1.5),ylims=(-1,2))
    plot!(p4)
    xlabel!(p4,"x")
    ylabel!(p4,"y")
    title!("Solution evolution for Explicit method")
end
gif(anim,"ExplicitMethod.gif")


#Part 4 Section 1 plot 1

FinalTime = 1;
tspan=(0,FinalTime);
dt=1/1024;

u=copy(u0)
u_store_eul=solve(ForwardEuler(), u, rhs!, tspan, dt, parameters; num_saved_steps=1);
p5=plot()
scatter!(p5,u_store_eul[1][1,1:100],u_store_eul[1][2,1:100],xlims=(-1,1),ylims=(-1,1.5),label="Initial positions")
scatter!(p5,u_store_eul[1][3,1:100],u_store_eul[1][4,1:100],xlims=(-1,1),ylims=(-1,1.5),label="Final Positions")
xlabel!(p5,"x")
ylabel!(p5,"y")
title!(p5,"Initial and final particle positions for Euler's Method")
savefig("plot5.png")


u=copy(u0)
u_store_mid=solve(ExplicitMidpoint(u), u, rhs!, tspan, dt, parameters; num_saved_steps=1);
p6=plot()
scatter!(p6,u_store_mid[1][1,1:100],u_store_mid[1][2,1:100],xlims=(-1,1),ylims=(-1,1.5),label="Initial positions")
scatter!(p6,u_store_mid[1][3,1:100],u_store_mid[1][4,1:100],xlims=(-1,1),ylims=(-1,1.5),label="Final Positions")
xlabel!(p6,"x")
ylabel!(p6,"y")
title!(p6,"Initial and final particle positions for Explicit Method")
savefig("plot6.png")
