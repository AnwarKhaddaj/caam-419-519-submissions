struct ExplicitMidpoint{T}
    u_tmp::T
    ExplicitMidpoint(u) = new{typeof(u)}(similar(u))
end

struct ForwardEuler
end

function solve(method, u0, rhs!, tspan, dt, parameters; num_saved_steps=1)
end

function solve(method::ForwardEuler, u0, rhs!, tspan, dt, parameters; num_saved_steps=1)
    # to compare to the solution at the final time
    du = similar(u0)
    Nsteps = ceil(Int, (tspan[2]-tspan[1]) / dt)
    num_saved_steps=min(num_saved_steps,Nsteps)
    u_store=zeros(num_saved_steps*size(u0,1)+2,size(u0,2))
    u_store[1:2,1:size(u0,2)]=u0; #storing the initial conditions
    if num_saved_steps==1
        index=Nsteps
    else
        index=round.(range(1,Nsteps,num_saved_steps))
    end
    counteval=0;
    t=tspan[1]
    c=3;
    for i = 1:Nsteps
        rhs!(du, u0, parameters, t)
        counteval=counteval+1;
        # the following loops are also equivalent to "@. u = u + dt * du"
        for j = 1:size(u0, 2)
            for i = 1:size(u0, 1)
                u0[i,j] = u0[i,j] + dt * du[i,j]
            end
        end
        if i in index
            u_store[c:c+1,:]=copy(u0);
            c=c+2;
        end
        t = t + dt
    end
    return (u_store,counteval)
end



function solve(method::ExplicitMidpoint, u0, rhs!, tspan, dt, parameters; num_saved_steps=1)
    A=ExplicitMidpoint(u0)
    u_tmp=A.u_tmp
    Nsteps = ceil(Int, (tspan[2]-tspan[1]) / dt)
    num_saved_steps=min(num_saved_steps,Nsteps)
    u_store=zeros(num_saved_steps*size(u0,1)+2,size(u0,2))
    u_store[1:2,1:size(u0,2)]=u0; #storing the initial conditions
    if num_saved_steps==1
        index=Nsteps
    else
        index=round.(range(1,Nsteps,num_saved_steps))
    end
    counteval=0;
    du = similar(u0)
    t=tspan[1]
    c=3;
    for i = 1:Nsteps
        rhs!(du, u0, parameters, t)
        counteval=counteval+1;
        # the following loops are also equivalent to "@. u = u + dt * du"
        for j = 1:size(u0, 2)
            for i = 1:size(u0, 1)
                u_tmp[i,j]=u0[i,j]+0.5*dt * du[i,j]
            end
        end
        rhs!(du, u_tmp, parameters, t+0.5*dt)
        counteval=counteval+1;
        # the following loops are also equivalent to "@. u = u + dt * du"
        for j = 1:size(u0, 2)
            for i = 1:size(u0, 1)
                u0[i,j]=u0[i,j]+dt*du[i,j]
            end
        end
        if i in index
            u_store[c:c+1,:]=copy(u0);
            c=c+2;
        end
        t = t + dt
    end
    return (u_store,counteval)
end
