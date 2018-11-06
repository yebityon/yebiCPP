if has('vim_starting')
  set runtimepath+=~/.vim/bundle/neobundle.vim/
endif
call neobundle#begin(expand('~/.vim/bundle/'))
" Let NeoBundle manage NeoBundle
NeoBundleFetch 'Shougo/neobundle.vim'
NeoBundle 'thinca/vim-quickrun'
NeoBundle 'w0ng/vim-hybrid'
NeoBundle 'tomasr/molokai'
NeoBundle 'jacoborus/tender.vim'
NeoBundle 'Yggdroot/indentLine'
NeoBundle 'cohama/lexima.vim'
" add plugins
call neobundle#end()
fu! Single_quote(str)
  return "'" . substitute(copy(a:str), "'", "''", 'g') . "'"
endfu
fu! Cabbrev(key, value)
  exe printf('cabbrev <expr> %s (getcmdtype() == ":" && getcmdpos() <= %d) ? %s : %s',
    \ a:key, 1+len(a:key), Single_quote(a:value), Single_quote(a:key))
endfu
"}}}
call Cabbrev('qr',  'QuickRun')
"for lexima.vim
call lexima#add_rule({'at': '\%#.*[-0-9a-zA-Z_,:]', 'char': '{', 'input': '{'})
call lexima#add_rule({'at': '\%#\n\s*}', 'char': '}', 'input': '}', 'delete': '}'})
filetype plugin on
NeoBundleCheck
" user setting
syntax on
colorscheme tender
set number
set tabstop=2     " 画面上でタブ文字が占める幅
set shiftwidth=2  " 自動インデントでずれる幅
set softtabstop=2 " 連続した空白に対してタブキーやバックスペースキーでカーソルが動く幅
set autoindent    " 改行時に前の行のインデントを継続する
set smartindent   " 改行時に入力された行の末尾に合わせて次の行のインデントを増減する
" OSのクリップボードをレジスタ指定無しで Yank, Put 出来るようにする
set clipboard=unnamed,unnamedplus
set virtualedit=onemore
set whichwrap=b,s,h,l,<,>,[,]
set backspace=indent,eol,start "backspaeceで行末とインデントの削除をできるようにする
"マウスの入力を受け付ける
set mouse=a
inoremap <silent> jj <ESC>  
inoremap <silent> jj <ESC>:w<CR>
set list listchars=tab:\|\ 
set conceallevel=1
let g:indentLine_conceallevel=1
let g:indentLine_color_term = 239
let g:indentLine_char = '|'
" indentLine
