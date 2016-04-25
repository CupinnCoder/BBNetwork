Pod::Spec.new do |s|
  s.name         = “BBNetwork"
  s.version      = "0.0.1"
  s.summary      = "iOS底层网络框架"
  s.homepage     = "https://github.com/CupinnCoder/BBNetwork"
  s.license      = "Copyright (C) 2016 Gary, Inc.  All rights reserved."
  s.author             = { "zhuguanyu" => “zhuguanyu@cupinn.cn" }
  s.ios.deployment_target = “7.0”
  s.source       = { :git => "https://github.com/CupinnCoder/BBNetwork.git"}
  s.source_files  = “BBNetwork/BBNetwork/**/*.{h,m,c}"
  s.requires_arc = true
  s.dependency 'MPMessagePack'
  s.dependency 'AFNetworking'
end
