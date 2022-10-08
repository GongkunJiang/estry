"show line number
set nu

"highlight search
set hls

"enable search parent directory
set tag=./tags;
set tags+=~/myWorkPlace/eswin/mbedtls-2.7.17/tags

"tabstop i.e. indent
set ts=4

"disable tab to space
set noexpandtab

"hide invisible characters
set nolist

"auto indent
set ai

" 状态栏
set laststatus=2      " 总是显示状态栏
highlight StatusLine cterm=bold ctermfg=yellow ctermbg=blue
" 获取当前路径，将$HOME转化为~
function! CurDir()
        let curdir = substitute(getcwd(), $HOME, "~", "g")
        return curdir
endfunction
set statusline=[%n]\ %f%m%r%h\ \|\ \ pwd:\ %{CurDir()}\ \ \|%=\|\ %l,%c\ %p%%\ \|\ ascii=%b,hex=%b%{((&fenc==\"\")?\"\":\"\ \|\ \".&fenc)}\ \|\ %{$USER}\ @\ %{hostname()}\
