;;; Directory Local Variables
;;; For more information see (info "(emacs) Directory Variables")

((c++-mode . ((company-clang-use-compile-flags-txt . t)
              (company-clang-arguments . ("-I src"))
              (compile-command . "cmake --build build")
              (c-basic-offset . 4))))
