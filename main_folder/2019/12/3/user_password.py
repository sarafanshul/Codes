def password_validation_check(pwd):
    if len(pwd) < 6 or len(pwd)>12:
        print(pwd, '의 길이가 적당하지 않습니다.')
        return False
    for c in pwd:
        if not c.isnumeric() and not c.isalpha():
            print(pwd, "특수 문자 사용은 불가능합니다.")
            return False
    b=pwd.upper()
    c=pwd.lower()
    if b == pwd or c==pwd:
        print(pwd, "비밀번호에 소문자, 대문자가 모두 포함되어야 합니다.")
        return False
    print(pwd, "는 적당한 비밀번호 입니다")
    return True
password_validation_check('23jke')
password_validation_check("432rewvb53")
password_validation_check("2@3jke%")
password_validation_check("3k39QLe6o0")
