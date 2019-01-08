//
//  AssistanceContactViewController.swift
//  Health Hearts at Home
//
//  Created by Luis Enrique Alvarez on 3/14/18.
//  Copyright © 2018 Luis Enrique Alvarez. All rights reserved.
//

import UIKit
import Contacts

class AssistanceContactViewController: UIViewController {

    @IBOutlet weak var clearButton: UIBarButtonItem!
    @IBOutlet weak var firstNameTextField: UITextField!
    @IBOutlet weak var lastNameTextField: UITextField!
    
    @IBAction func clearBtnClicked(_ sender: UIBarButtonItem) {
        resetAction()
    }
    //    @IBOutlet weak var fullNameTextField: UITextField!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        clearButton.title = "Clear"
        // Do any additional setup after loading the view.
    }

    func resetAction(){
        print("button reset has been called")
//        let domain = Bundle.main.bundleIdentifier!
//        UserDefaults.standard.removePersistentDomain(forName: domain)
//        UserDefaults.standard.synchronize()
//        print(Array(UserDefaults.standard.dictionaryRepresentation().keys).count)
        //-> the code above is to delete all store data in UserDefault
        UserDefaults.standard.removeObject(forKey: "saveContact")
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
