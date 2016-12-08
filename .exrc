function! neomake#makers#ft#cpp#clang() abort
    let maker = neomake#makers#ft#c#clang()
    let maker.exe = 'clang++'
    let maker.args = ['-Iextern/catch/include', '-Isrc']
    return maker
endfunction
