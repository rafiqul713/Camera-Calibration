import calibration
obj= calibration.MyCalibration()
obj.input_directory("./images/*.jpg")
obj.configure_board(6,9)
obj.initialization()
obj.calibration_process()