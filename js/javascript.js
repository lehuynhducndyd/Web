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

function thongbao1(){
    alert("Chức năng đang được phát triển")
}

function kt(){
    var f =document.getElementById('RegistForm');
    var emailReg = /^[a-zA-Z0-9_-]+@[a-zA-Z0-9.-]+\.[a-zA-z]{2,4}$/;
    if(emailReg.test(f.email.value) == false){
        document.getElementById('emailInvalid').innerText = '* Email không hợp lệ'; 
        document.getElementById('passInvalid').innerText = '';
        document.getElementById('rePassInvalid').innerText = '';
        f.email.focus();
        return false;
    }
    var passReg = /^(?=.*?[A-Z])(?=.*?[a-z])(?=.*?[0-9])(?=.*?[#?!@$%^&*-]).{8,}$/g;
    if(passReg.test(f.pwd.value)==false){
        document.getElementById('passInvalid').innerText = '* Mật khẩu không hợp lệ';
        document.getElementById('emailInvalid').innerText ='';
        document.getElementById('rePassInvalid').innerText = '';
        f.pwd.focus();
        return false;
    }
    if(f.repwd.value != f.pwd.value){
        document.getElementById('rePassInvalid').innerText = '* Mật khẩu chưa khớp';
        document.getElementById('emailInvalid').innerText ='';
        document.getElementById('passInvalid').innerText = '';
        f.repwd.focus();
        return false;
    }

    var email = f.email.value.trim();
    var password = f.pwd.value.trim();

    // Kiểm tra xem tên đăng nhập đã tồn tại hay chưa
    const existingUsers = localStorage.getItem('registeredUsers') || '{}';
    const parsedUsers = JSON.parse(existingUsers);

    if (parsedUsers[email]) {
        alert('Email đã được sử dụng!');
        f.email.focus();
        return false;
    }

    // Lưu thông tin đăng ký vào Local Storage
    parsedUsers[email] = password;
    localStorage.setItem('registeredUsers', JSON.stringify(parsedUsers));

    alert('Đăng ký thành công!');
    

    // Xóa dữ liệu trong form

    // var phoneReg =/^[+]{1}(?:[0-9\-\\(\\)\\/.]\s?){6,15}[0-9]{1}$/;
    // if(phoneReg.test(f.pnumber.value) == false){
    //     document.getElementById('phoneInvalid').innerText = '* Số điện thoại không hợp lệ';
    //     f.pnumber.focus();
    //     return false;
    // }
    // const emailDangNhap = document.getElementById('email').value;
    // const matKhau = document.getElementById('pwd').value;

    // // Lưu thông tin đăng ký vào LocalStorage
    // localStorage.setItem('emailDangNhap', emailDangNhap);
    // localStorage.setItem('matKhau', matKhau);
    // alert('Đăng ký thành công!');
    // window.location="index.html";

};


function DangNhap() {
    const loginForm = document.getElementById('LoginForm');
 

    const loginEmail = loginForm.email.value.trim();
    const loginPassword = loginForm.pwd.value.trim();

  // Retrieve registered users from Local Storage
    var existingUsers = localStorage.getItem('registeredUsers') || '{}';
    var parsedUsers = JSON.parse(existingUsers);

  // Check if username and password match a registered user
  if (parsedUsers[loginEmail] && parsedUsers[loginEmail] === loginPassword) {
    alert('Đăng nhập thành công!');
    window.location="index.html";
    // Perform actions after successful login (e.g., redirect to user profile)
  } else {
    alert('Tên đăng nhập hoặc mật khẩu không chính xác!');
    return false;
  }

};
