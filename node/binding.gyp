{
  "targets": [
    {
      "target_name": "calculator",
      "sources": [
        "calculator.cpp",
        "../src/calculator.cpp"
      ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")",
        "../include",
        "../node_modules" 
      ],
      "dependencies": [
        "<!(node -p \"require('node-addon-api').gyp\")"
      ],
      "cflags!": ["-fno-exceptions"],
      "cflags_cc!": ["-fno-exceptions"],
      "defines": ["NAPI_CPP_EXCEPTIONS"],
      "libraries": []
    }
  ]
}
