function ktdk(f){
    window.localStorage.clear()
    window.localStorage.setItem('username',f.username.value)
    window.localStorage.setItem('password',f.password.value)
    window.localStorage.setItem('phone',f.phone.value)
    window.localStorage.setItem('fullname',f.fullname.value)
    window.localStorage.setItem('address',f.address.value)
    var passReg = /^(?=.*?[A-Z])(?=.*?[a-z])(?=.*?[0-9])(?=.*?[#?!@$%^&*-]).{8,}$/g
    if(passReg.test(f.password.value)==false){
        alert("Mật khẩu chứa ít nhất 1 chữ hoa, 1 chữa số, 1 chữ thường, 1 kí tự đặc biệt, tối thiểu 8 kí tự")
        f.password.focus()
        return false
    }
    if(f.password.value != f.repassword.value){
        alert("vui long nhap lai mat khau dung")
        f.repassword.focus()
        return false
    }
    if(f.phone.value.length <10 || f.email.value.length >10){
        alert("vui lòng nhập sđt đúng")
        f.phone.focus()
        return false
    }
    alert("Đăng ký thành công")
    
    return true
}
function ktdn(f) {
    if(window.localStorage.getItem("username") == f.username.value && window.localStorage.getItem("password") == f.password.value){
        alert("Đăng nhập thành công")
        return true
    }
    alert("Tên đăng nhập hoặc mật khẩu không chính xác")
    return false
}

var data= '{"user":[{"username":"duc","password":"123456"},{"username":"duong","password":"abcdef"}]}'
obj=JSON.parse(data)

function ktdnad(f){
    for(i=0;i<obj.user.length;i++){
        if(obj.user[i].username == f.username.value && obj.user[i].password == f.password.value){
            alert("Đăng nhập thành công")
            return true
        }
    }
    alert("Tên đăng nhập hoặc mật khẩu không chính xác")
    return false
}
