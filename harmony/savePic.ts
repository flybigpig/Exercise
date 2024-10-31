function savePicDialog(a: string) {

    let customerAlertController = new CustomDialogController({
      builder: SavePicDialog({
        title: "提示",
        message: "保存图片到相册？",
        onCancel: () => {
          customerAlertController.close()
        },
        onConfirm: () => {
          try {
            // 取消异步
            //权限申请成功，保存到图库
            let context = getContext();
            let data = plainToClass(Base64DataPhoto, JSON.parse(a))
            let dataBuffer = buffer.from(data.imgData, 'base64')
            //获取相册管理模块的实例，用于访问和修改相册中的媒体文件
            let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
            // onClick触发后10秒内通过createAsset接口创建图片文件，10秒后createAsset权限收回
            phAccessHelper.createAsset(photoAccessHelper.PhotoType.IMAGE, 'jpg').then((value: string) => {
              // let uri = await phAccessHelper.createAsset(photoAccessHelper.PhotoType.IMAGE, 'jpg');
              let uri = value
              console.log(uri);
              // 创建媒体文件
              console.info('createAsset successfully, uri: ' + uri);
              let file = fs.openSync(uri, fs.OpenMode.READ_WRITE || fs.OpenMode.CREATE);
              let writeLen = fs.writeSync(file.fd, dataBuffer.buffer);
              let totalSize = 0;
              fs.close(file);
            })
          } catch (e) {
            console.log(JSON.stringify(e));
          }
          customerAlertController.close()
        }
      }),
      openAnimation: {
        duration: 200,
        curve: Curve.Friction,
        delay: 50,
        playMode: PlayMode.Alternate,
        onFinish: () => {
        }
      },
      autoCancel: true,
      alignment: DialogAlignment.Center,
      // offset: { dx: 0, dy: -20 },
      gridCount: 5,
      customStyle: true,
      backgroundColor: Color.Transparent,
      // cornerRadius: 1,
    })
    customerAlertController.open()
  }