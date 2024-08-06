from django.shortcuts import render, redirect
from django.contrib.auth import authenticate,login,logout
from hashlib import sha256
from .models import User,Task
# Create your views here.
def login_user(request):
    if request.method == 'POST':
        data = request.POST
        email = data.get('email')
        password = data.get('password')
        hashpd = sha256(password.encode()).hexdigest()
        user = User.objects.filter(email = email,password = hashpd)
        if User is not None:
            return redirect('/home/')
        else:
            return render(request,'login.html',{'message':'email or password is incorrect'})
    return render(request,'login.html')
def signup_user(request):
    if request.method == 'POST':
        data = request.POST
        email = data.get('email')
        if User.objects.filter(email=email).exists():
            return render(request,'signup.html',{'message':'Email already exist'})
        password1 = data.get('password1')
        password2 = data.get('password2')
        if password1 != password2:
            return render(request,'signup.html',{'message':'both password must be equal'})
        hashpd = sha256(password1.encode()).hexdigest()
        newuser = User(email = email,password = hashpd)
        newuser.save()
        return redirect('/auth/login/')
    return render(request,'signup.html')

def taskmanager(request):
    if request.method=='POST':
        data = request.POST
        mytask = data.get('mytask')
        Task.objects.create(mytask = mytask)
        return redirect('/taskmanager')
    queryset = Task.objects.all()
    context = {
        'mytask' :queryset
    }
    return render(request,'/Users/mdehteshamansari00/DSA_challenge/Task_Rabbit/taskrabbit/myapp/templates/taskmanager.html',context)
def delete_task(request):
    queryset = Task.objects.get(id=id)
    queryset.delete()
def updatetask(request):
    queryset = Task.objects.get(id=id)
    if request.method=='POST':
        data = request.POST
        mytask = data.get('mytask')
        queryset.mytask = mytask
        queryset.save()
        return redirect('/taskmanager')
    context = {
        'mytask' :queryset
    }
    return render(request,'/Users/mdehteshamansari00/DSA_challenge/Task_Rabbit/taskrabbit/myapp/templates/taskmanager.html',context)