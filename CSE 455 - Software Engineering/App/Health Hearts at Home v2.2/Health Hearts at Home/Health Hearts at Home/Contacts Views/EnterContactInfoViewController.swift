//
//  EnterContactInfoViewController.swift
//  Health Hearts at Home
//
//  Created by Luis Enrique Alvarez on 3/13/18.
//  Copyright © 2018 Luis Enrique Alvarez. All rights reserved.
//

import UIKit
import Contacts

class EnterContactInfoViewController: UIViewController {

    @IBOutlet weak var firstNameTextField: UITextField!
    @IBOutlet weak var secondNameTextField: UITextField!
    @IBOutlet weak var thirdNumberTextField: UITextField!
    @IBOutlet weak var resetButton: UIBarButtonItem!
    
    @IBAction func resetDeleteInfo(_ sender: UIBarButtonItem) {
        resetAction()
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        resetButton.title = "Reset"
    
        // Do any additional setup after loading the view.
    }

    func resetAction(){
        //This will delete ALL USER DEFAULTS ....
                print("button reset has been called")
//                let domain = Bundle.main.bundleIdentifier!
//                UserDefaults.standard.removePersistentDomain(forName: domain)
//                UserDefaults.standard.synchronize()
//                print(Array(UserDefaults.standard.dictionaryRepresentation().keys).count)
        //.........This is temporary depending on how you wish to proceed
        
        UserDefaults.standard.removeObject(forKey: "deletedInfo")
        UserDefaults.standard.removeObject(forKey: "orderItems")
    }
    
/* This is how you would pass data if the view controller was A
  and ShortBreak view controler was B -> the current state is the opposite*/
//    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
//
//        guard let shortVC = segue.destination as? ShortBreakViewController else {return}
//
//        let name = firstNameTextField.text
//        let familyname = secondNameTextField.text
//        let number = thirdNumberTextField.text
//
////        contact.imageData = Data()
////        contact.givenName = name!
////        contact.familyName = familyname!
////        contact.phoneNumbers = [CNLabeledValue(label: CNLabelPhoneNumberMobile, value: CNPhoneNumber(stringValue: "\(String(describing: number))"))]
////
////        let store = CNContactStore()
////        let saveRequest = CNSaveRequest()
////        saveRequest.add(contact, toContainerWithIdentifier: nil)
//////        store.execute
////
////        do{
////            try store.execute(saveRequest)
////
////        }catch{
////
////        }
//
//
//        let contactToAppend = ContactStruct(name: name!, familyName: familyname!, number: number!)
//        shortVC.newContacts.append(contactToAppend)
//    }
    


    
    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
